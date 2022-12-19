#include "LinkedList.cpp"

#ifndef NODE_HPP
#define NODE_HPP

using namespace std;

template <class T>

class Node{
    
    private:
        std::unique_ptr<T> data;
        LinkedList<Node>* neighbours;

    public:

        Node();

        Node(T content);

        ~Node();

        void set(T content);

        T get() const;

        const string toString() const;
};


#endif