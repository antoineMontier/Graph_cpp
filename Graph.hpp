#include "Node.cpp"

#ifndef GRAPH_HPP
#define GRAPH_HPP

using namespace std;

template <class T>

class Graph{
    
    private:
        LinkedList<Node<T> *> *nodes;

        bool searchFrom(Node<T> *from, Node<T> *to, LinkedList<Node<T> *> *unvisit_list, bool directed, bool ignore_first) const;

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

        bool directedPathExists(Node<T> *from, Node<T> *to) const;

        bool undirectedPathExists(Node<T> *from, Node<T> *to) const;

        bool isStronglyConnected() const;

        bool isWeaklyConnected() const;

        bool isComplete() const;

        bool isCycle() const; // works but even if the cycle is between two nodes like this <---> ...

        //bool isDirectedTree() const;

        bool isUndirectedTree() const;

        //bool isForest() const;

        bool isStrongArticulation(Node<T> * n);//const methodes but i modify twice 'this' object so i can't write const

        bool isWeakArticulation(Node<T> * n);//const methodes but i modify twice 'this' object so i can't write const

        bool canBeFlat() const;

        //bool isBipartite() const;
};


#endif