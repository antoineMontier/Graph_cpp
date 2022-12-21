#include "Graph.hpp"
using namespace std;

template <class T>
Graph<T>::Graph()
{
    nodes = new LinkedList<Node<T> *>();
}

template <class T>
Graph<T>::~Graph()
{
    if (nodes != nullptr)
        delete nodes;
}

template <class T>
const string Graph<T>::toString() const
{
    ostringstream buffer;
    buffer << "nodes number : " << countNodes() << endl;
    // add a edge counter
    buffer << "edges number : " << countEdges() << endl;
    int neighbours_displayed;
    for (int i = 0; i < countNodes(); i++)
    {
        neighbours_displayed = 0;
        buffer << nodes->get(i)->toString() << "\n";
        while (neighbours_displayed < nodes->get(i)->neighboursCount())
        {
            for (int node_id = 0; node_id < countNodes(); node_id++)
            {
                if (nodes->get(i)->isLinked(nodes->get(node_id)))
                {
                    buffer << "  |------> " << nodes->get(node_id)->toString() << "\n";
                    neighbours_displayed++;
                }
            }
        }
        buffer << "\n";
    }
    return buffer.str();
}

template <class T>
long Graph<T>::countNodes() const
{
    return nodes->size();
}

template <class T>
long Graph<T>::countEdges() const
{
    long count = 0;
    for (int i = 0; i < countNodes(); i++)
        count += nodes->get(i)->neighboursCount();
    return count;
}

template <class T>
bool Graph<T>::isNodePresent(Node<T> *node) const
{
    return nodes->contains(node);
}

template <class T>
bool Graph<T>::addNode(Node<T> *node)
{
    if (node == nullptr)
    {
        throw std::invalid_argument("you can't add a null node");
        return false;
    }
    // assert node isn't already in the graph
    if (isNodePresent(node))
        return false;
    nodes->pushTail(node);
    return true;
}

template <class T>
bool Graph<T>::addEdge(Node<T> *from, Node<T> *to)
{
    if (from == nullptr || to == nullptr)
    {
        throw std::invalid_argument("you can't link from or to a null node");
        return false;
    }
    // first assert that the source and destination are in the graph :
    if (!isNodePresent(from) || !isNodePresent(to))
        return false;
    // add the edge
    from->linkTo(to);
    return true;
}

template <class T>
bool Graph<T>::addDoubleEdge(Node<T> *from, Node<T> *to)
{
    if (from == nullptr || to == nullptr)
    {
        throw std::invalid_argument("you can't link from or to a null node");
        return false;
    }
    // first assert that the source and destination are in the graph :
    if (!isNodePresent(from) || !isNodePresent(to))
        return false;
    // add the edges
    from->linkTo(to);
    to->linkTo(from);
    return true;
}

template <class T>
bool Graph<T>::removeNode(Node<T> *node)
{
    if (node == nullptr)
    {
        throw std::invalid_argument("you can't remove a null node");
        return false;
    }
    // assert node is in the graph
    if (!isNodePresent(node))
        return false;
    // first remove the node "N-------->Other" connexions
    node->unlinkAll();
    // then remove the node "Other----->N" connexions
    for (int i = 0; i < nodes->size(); i++)
        while (nodes->get(i)->isLinked(node))
            removeEdge(nodes->get(i), node);
    // remove the node
    for (int i = 0; i < nodes->size(); i++)
        if (nodes->get(i) == node)
        {
            nodes->pop(i);
            return true;
        }
    return false;
}

template <class T>
bool Graph<T>::removeEdge(Node<T> *from, Node<T> *to)
{
    if (from == nullptr || to == nullptr)
    {
        throw std::invalid_argument("you can't unlink from or to a null node");
        return false;
    }
    // assert that the source and destination are in the graph :
    if (!isNodePresent(from) || !isNodePresent(to))
        return false;
    // remove the edge
    return from->unlink(to);
}

template <class T>
bool Graph<T>::isDirected() const
{ // we're ckecking if every edge is double linked (except for loops)
    for (int i = 0; i < nodes->size(); i++)
    {
        int neighbours_to_test = nodes->get(i)->neighboursCount();
        if (nodes->get(i)->isLinked(nodes->get(i)))
            neighbours_to_test--; // don't count the loops
        while (neighbours_to_test > 0)
        {
            for (int j = 0; j < nodes->size(); j++)
            {
                if (nodes->get(i)->isLinked(nodes->get(j)))
                {
                    neighbours_to_test--;
                    if (!nodes->get(j)->isLinked(nodes->get(i)))
                        return false;
                }
            }
        }
    }
    return true;
}

/*
template <class T>
bool Graph<T>::isWeaklyConnected()() const{// a graph is Weakly Connected if it's possible to travel from any node to any other node replacing every edge by double edges
    if(nodes->size() < 2)
        return true;
    for(int i = 0; i < nodes->size(); i++)
        for(int j = i + 1; j < nodes->size(); j++)
            if(!nodes->get(i)->isLinked(nodes->get(j)) && !nodes->get(j)->isLinked(nodes->get(i)))//no connections
                return false;
    return true;
}
*/




template <class T>
bool Graph<T>::pathExists(Node<T> *from, Node<T> *to) const
{
    if (from == nullptr || to == nullptr)
        throw std::invalid_argument("you can't find a path involving a null node");
    if (!isNodePresent(from) || !isNodePresent(to))
        return false;
    if (from == to)
        return true;
    if (from->neighboursCount() == 0)
        return false;
    // search recursively
    LinkedList<Node<T> *> *unvisited = new LinkedList<Node<T> *>;
    for (int i = 0; i < nodes->size(); i++)
        if (nodes->get(i) != from)
        {
            unvisited->push(nodes->get(i));
        }
    return searchFrom(from, to, unvisited);
}

template <class T>
bool Graph<T>::searchFrom(Node<T> *from, Node<T> *to, LinkedList<Node<T> *> *unvisit_list) const
{
    // std::cout << "search" << endl;
    if (from == nullptr || to == nullptr)
        return false;
    if (from == to)
    {
        return true;
    }
    if (unvisit_list->size() == 0)
    {
        delete unvisit_list;
        return false;
    }
    LinkedList<Node<T> *> *unvisited_bis = new LinkedList<Node<T> *>;
    for(int i = 0; i < unvisit_list->size(); i++)
        if(unvisit_list->get(i) != from)
            unvisited_bis->push(unvisit_list->get(i));

    for (int i = 0; i < unvisited_bis->size(); i++)
        if (from->isLinked(unvisited_bis->get(i)))
        {
            if (searchFrom(unvisited_bis->get(i), to, unvisited_bis) == true)
                return true;
        }

    // std::cout << "last false" << endl;
    return false;
}




/*
template <class T>
bool Graph<T>::pathExists(Node<T> *from, Node<T> *to) const
{
    if (from == nullptr || to == nullptr)
        throw std::invalid_argument("you can't find a path involving a null node");
    if (!isNodePresent(from) || !isNodePresent(to))
        return false;
    if (from == to)
        return true;
    if (from->neighboursCount() == 0)
        return false;

    // search recursively
    LinkedList<Node<T> *> *unvisited = new LinkedList<Node<T> *>;
    unvisited->push(from);
    return searchFrom(from, to, unvisited);
}

template <class T>
bool Graph<T>::searchFrom(Node<T> *from, Node<T> *to, LinkedList<Node<T> *> *unvisit_list) const
{
    // std::cout << "search" << endl;
    if (from == nullptr || to == nullptr)
        return false;
    if (from == to)
    {
        std::cout << "direct true   ";
        return true;
    }
    if (unvisit_list->size() == 0)
    {
        delete unvisit_list;
        return false;
    }



    // Update the list of neighbors to include only those
    // that have not yet been visited
    LinkedList<Node<T> *> *neighbors = new LinkedList<Node<T> *>;
    for (int i = 0; i < from->neighboursCount(); i++)
    {
        Node<T> *neighbor = from->getNeighbours().get(i);
        if (!neighbor->visited)
            neighbors->push(neighbor);
    }

    // Search for a path from each unvisited neighbor
    for (int i = 0; i < neighbors->size(); i++)
    {
        if (searchFrom(neighbors->get(i), to, unvisit_list))
        {
            delete neighbors;
            return true;
        }
    }

    delete neighbors;
    return false;
}
*/