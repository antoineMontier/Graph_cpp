#include "Cell.hpp"
#include "Cell.cpp"

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

using namespace std;

template <class T>

class LinkedList{
    
    private:
        Cell<T> * head;
        Cell<T> * tail;

    public:

        LinkedList();

        LinkedList(T content);

        ~LinkedList();

        void push(T content);


        const string toString() const;

};


#endif