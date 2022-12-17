#include "LinkedList.hpp"
using namespace std;

template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList(){
    head = nullptr;
    tail = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(Cell<T> new_head){
    head = &new_head;
    tail = head;
}
template <class T>

const string LinkedList<T>::toString() const{
    if(head == nullptr){
        return "[-]";
    }
    ostringstream buffer;
    buffer<<"[";
    Cell<T> walker = Cell(*head);
    while (head->hasNext())
    {
        buffer<<walker.toString();
        walker = walker.getNext();
    }
    buffer<<(*tail).toString()<<"]";
    return buffer.str();
}