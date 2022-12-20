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

        const string toString() const;
        
        long countNodes() const;

        long countEdges() const;//counting 2 edges if it's a double edge

        void addNode(Node<T> *node);

        bool isNodePresent(Node<T> *node) const;

        bool addEdge(Node<T> *from, Node<T> *to);
};


#endif