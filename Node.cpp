#include "Node.hpp"
using namespace std;

template <class T>
Node<T>::Node()
{
    data = nullptr;
    neighbours = new LinkedList<Node<T>*>();
}

template <typename T>
Node<T>::Node(const Node<T> &other){
    // Copy the data
    if(other.data != nullptr){
        data = std::make_unique<T>(other.get());
    }else{
        data = nullptr;
    }

    // Allocate memory
    neighbours = new LinkedList<Node<T>*>();

    // Copy the neighbours list from the other 
    for (int i = 0; i < other.neighbours->size(); i++) {
        neighbours->pushTail(other.neighbours->get(i));
    }
}


template <class T>
Node<T>::Node(T content){
    data = std::make_unique<T>(content);
    neighbours = new LinkedList<Node<T>*>();
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
    if(data != nullptr)
        return *data;
    else
        return T();
}

template <class T>
const string Node<T>::toString() const{
    ostringstream buffer;
    if(data != nullptr)
        buffer <<"("<< *data<<")";
    else
        buffer << "-";
    //buffer << " | nb : " << neighbours->size();
    return buffer.str();
}

template <class T>
void Node<T>::linkTo(Node* node){
    neighbours->pushTail(node);
}

template <class T>
bool Node<T>::isLinked(Node* node) const{
    return neighbours->contains(node);
}

template <class T>
int Node<T>::neighboursCount() const{
    return neighbours->size();
}
template <class T>
bool Node<T>::unlink(Node* node){
    if(!isLinked(node))
        return false; // no unlike possible
    for(int i = 0; i < neighboursCount(); i++)
        if(neighbours->get(i) == node){
            neighbours->pop(i);
            return true;
        }
    return false;
}

template <class T>
void Node<T>::unlinkAll(){
    if(neighbours->size() == 0) return;
    for(int i = neighboursCount()-1; i >= 0 ; i--){
        neighbours->pop(i);
    }
}

template <class T>
const LinkedList<Node<T> *>* Node<T>::getNeighbours() const{
    return neighbours;
}