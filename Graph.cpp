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