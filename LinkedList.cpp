#include "LinkedList.hpp"
using namespace std;

template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList(){
    free(head);
    free(tail);
}

template <class T>
LinkedList<T>::LinkedList(T content){
    Cell<T>* n_head = new Cell(content);//when using a pointer, add the "new"key word in front of the constructor
    //std::cout<<"n_head = "<<n_head->toString()<<endl;
    tail = n_head;
    //std::cout<<"tail = "<<(*tail).toString()<<endl;
    head = tail;
    //std::cout<<"head = "<<(*head).toString()<<endl;
}

template <class T>

const string LinkedList<T>::toString() const{
    if(head == nullptr){
        return "[-]";
    }
    ostringstream buffer;
    buffer<<"[";
    Cell<T> *walker = head;
    //std::cout<<"walker initialized at "<<(*walker).toString()<<endl;
    while ((*walker).hasNext())
    {
        //std::cout<<"entering loop head = "<<(*head).toString()<<" next head = "<<(*head).getNext().toString()<<endl;
        //std::cout<< "loop entry, walker = "<<(*walker).toString()<<endl;
        buffer<< (*walker).toString()<<", ";
        //std::cout<<"buffer loaded"<<buffer.str()<<endl;
        walker = (*walker).getNextPtr();
        //std::cout<< "walker increased"<<endl;
    }
    buffer<<(*tail).toString()<<"]";
    return buffer.str();
}

template <class T>
void LinkedList<T>::push(T content){
    //std::cout<<"1"<<endl;
    Cell<T>* c = new Cell(content);
   

    //std::cout<<"head = "<< head<<" tail = "<< tail <<" c = " << c <<endl;

    //std::cout<<"2"<<endl;
    if(head == nullptr){
        //std::cout<<"1st"<<endl;
        head = c;
        //std::cout<<"1st ended"<<endl;
        tail = c;
        return;
    }else if(head == tail){
        //std::cout<<"2nd"<<endl;
        c->setNext(tail);
        head = c;
        //std::cout<<"2nd ended"<<endl;
        //no changes for tail
        //std::cout<<"after push head = "<<(*head).toString()<<" next head = "<<(*head).getNext().toString()<<" tail = "<<(*tail).toString()<<endl;
        //std::cout<<"head = "<< head<<" head next = "<<  (*head).getNext().toString()  <<" tail = "<< tail <<" c = " << c <<endl;

        return;
    }else{
        //std::cout<<"3rd"<<endl;
        c->setNext(head);
        //std::cout<<"3rd ended"<<endl;
        head = c;
    }
}