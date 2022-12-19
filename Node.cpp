#include "Node.hpp"
using namespace std;

template <class T>
Node<T>::Node()
{
    data = nullptr;
    neighbours = new LinkedList<Node>();
}

template <class T>
Node<T>::Node(T content){
    data = std::make_unique<T>(content);
    neighbours = new LinkedList<Node>();
}

template <class T>
Node<T>::~Node(){
    if(neighbours != nullptr)
        delete neighbours;
}