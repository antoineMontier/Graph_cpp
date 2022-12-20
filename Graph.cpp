#include "Graph.hpp"
using namespace std;


template <class T>
Graph<T>::Graph(){
    nodes = new LinkedList<Node<T>*>(); 
}



template <class T>
Graph<T>::~Graph(){
    if(nodes != nullptr)
        delete nodes;
}

template <class T>
const string Graph<T>::toString() const {
    ostringstream buffer;
    buffer << "nodes number : " << countNodes() <<endl;
    //add a edge counter
    buffer << "edges number : " << countEdges() <<endl;
    int neighbours_displayed;
    for(int i = 0; i < countNodes() ; i++){
        neighbours_displayed = 0;
        buffer << nodes->get(i)->toString()<<"\n";
        while (neighbours_displayed < nodes->get(i)->neighboursCount()){
            for (int node_id = 0; node_id < countNodes() ; node_id++){
                if(nodes->get(i)->isLinked(nodes->get(node_id))){
                    buffer <<  "  |------> " << nodes->get(node_id)->toString() << "\n";
                    neighbours_displayed++;
                }
            }
        }
        buffer << "\n";
    }
    return buffer.str();
}

template <class T>
long Graph<T>::countNodes() const {
    return nodes->size();
}

template <class T>
long Graph<T>::countEdges() const {
    long count = 0;
    for(int i = 0; i < countNodes(); i++)
        count += nodes->get(i)->neighboursCount();
    return count;
}

template <class T>
void Graph<T>::addNode(Node<T> *node) {
    if(node == nullptr)
        throw std::invalid_argument("you can't add a null node");
    nodes->pushTail(node);
}

template <class T>
bool Graph<T>::isNodePresent(Node<T> *node) const {
    return nodes->contains(node);
}

template <class T>
bool Graph<T>::addEdge(Node<T> *from, Node<T> *to){
    if(from == nullptr || to == nullptr)
        return false;       // error throwing would have been another way to do this
    //first assert that the source and destination are in the graph :
    if(!isNodePresent(from) ||!isNodePresent(to))
        return false;
    //add the edge
    from->linkTo(to);
    return true;
}  