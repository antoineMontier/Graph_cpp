#include "Node.cpp"

#ifndef GRAPH_HPP
#define GRAPH_HPP

using namespace std;

template <class T>

class Graph{
    
    private:
        LinkedList<Node<T> *> *nodes;
        
        bool tabContains(Node<T>** tab, Node<T> * target);

        bool placeZero(Node<T>** tab, Node<T> * target);


    public:

        Graph();

        ~Graph();

        const string toString() const;
        
        long countNodes() const;

        long countEdges() const;//counting 2 edges if it's a double edge

        bool addNode(Node<T> *node);

        bool removeNode(Node<T> *node);

        bool isNodePresent(Node<T> *node) const;

        bool addEdge(Node<T> *from, Node<T> *to);

        bool addDoubleEdge(Node<T> *from, Node<T> *to);

        bool removeEdge(Node<T> *from, Node<T> *to);

        bool isDirected() const;//can be improved 

        bool searchFrom(Node<T> *from, Node<T> *to, Node<T>** unvisit_array) const;

        bool pathExists(Node<T> *from, Node<T> *to) const;

        //bool isWeaklyConnected() const;
};


#endif