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
template <class T>
void Node<T>::set(T content){
    data = std::make_unique<T>(content);
}

template <class T>
T Node<T>::get() const{
    return *data;
}

template <class T>
const string Node<T>::toString() const{
    ostringstream buffer;
    if(data != nullptr)
        buffer << *data;
    else
        buffer << "-";
    return buffer.str();
}
