#include <iostream>
#include "cell.h"
using namespace std;

template <class T>

Cell<T>::Cell(T contenu, Cell<T> nextcell){
    this->content = contenu;
    this->next = &nextcell;
}


template <class T>

Cell<T>::~Cell(){
    delete this->content;
    delete this->next;
}

template <class T>

Cell<T>::Cell(){
    content = NULL;
    next = NULL;
}
template <class T>

Cell<T>::Cell(T cont){
    content = cont;
    next = NULL;
}
template <class T>


T Cell<T>::getContent(){
    return content;
}
template <class T>

void Cell<T>::setContent(T cont){
    content = cont;
}
template <class T>

Cell<T> Cell<T>::getNext(){
    return *next;
}
template <class T>

void Cell<T>::setNext(Cell<T> nextcell){
    next = &nextcell;
}
template <class T>


Cell<T>::operator std::string() const {
    return std::to_string(content);
}
template <class T>

bool Cell<T>::equal(Cell<T> other){
    return content == other.content && next == other.next;
}
