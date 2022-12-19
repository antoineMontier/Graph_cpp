#include "Cell.cpp"
#include <functional>

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

        void pushTail(T content);

        T pop();

        T popTail();

        int size() const;

        T get(int index) const;

        void set(int index, T content);

        T pop(int index);

        void push(int index, T content);

        bool equals(LinkedList<T> other) const;

        void bubbleSort(std::function <bool(T, T)> comparator);


        const string toString() const;

};


#endif