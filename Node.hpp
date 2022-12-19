#include "LinkedList.cpp"

#ifndef NODE_HPP
#define NODE_HPP

using namespace std;

template <class T>

class Node{
    
    private:
        std::unique_ptr<T> data;
        LinkedList<Node<T> *> *neighbours;

    public:

        Node();

        Node(T content);

        Node(const Node<T> &other);

        ~Node();

        void set(T content);

        T get() const;

        const string toString() const;

        void linkTo(Node* node);
};


#endif