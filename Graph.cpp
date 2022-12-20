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
    if (!isNodePresent(from) || !isNodePresent(to) || from->neighboursCount() == 0)
        return false;
    if (from == to)
        return true;
    // search recursively
    Node<T> *unvisited[nodes->size()];
    for (int i = 0; i < nodes->size(); i++)
        if (nodes->get(i) != from)
            unvisited[i] = nodes->get(i);
        else
            unvisited[i] = 0;
    return searchFrom(from, to, unvisited);
}

template <class T>
bool Graph<T>::tabContains(Node<T>** tab, Node<T> * target){
    for (int i = 0; i < nodes->size(); i++)
        if (tab[i] == target)
            return true;
    return false;
}

template <class T>
bool Graph<T>::placeZero(Node<T>** tab, Node<T> * target){
    for (int i = 0; i < nodes->size(); i++)
        if (tab[i] == target){
            tab[i] = 0;
            return true;
        }
    return false;
}


template <class T>
bool Graph<T>::searchFrom(Node<T> *from, Node<T> *to, Node<T> **unvisit_array) const
{
    std::cout << "search" << endl;
    if (from == nullptr || to == nullptr)
        return false;
    if (from == to)
        return true;
    bool everything_visited = true;
    for (int i = 0; i < nodes->size(); i++)
    {
        everything_visited = everything_visited && unvisit_array[i] == 0;
        if (everything_visited)
        {
            delete[] unvisit_array;
            return false;
        }
    }
    
    for (int i = 0 ; i < nodes->size(); i++)
        if(from->isLinked(nodes->get(i)) && tabContains(unvisit_array, nodes->get(i))){
            placeZero(unvisit_array, nodes->get(i));
            if(searchFrom(nodes->get(i), to, unvisit_array))
                return true;
        }
        
    std::cout << "last false" << endl;
    return false;
}
