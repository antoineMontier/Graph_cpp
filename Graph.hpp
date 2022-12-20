#include "Node.cpp"

#ifndef GRAPH_HPP
#define GRAPH_HPP

using namespace std;

template <class T>

class Graph{
    
    private:
        LinkedList<Node<T> *> *nodes;

    public:

        Graph();

        ~Graph();
};


#endif