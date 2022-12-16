#include <iostream>
#include "cell.h"
using namespace std;

template <class t> class Cell{
    private:
    t content;
    Cell<t> *next;

    public:
    Cell(t cont, Cell<t> nextcell){
        content = cont;
        next = &nextcell;
    }
    Cell(){
        content = NULL;
        next = NULL;
    }

    Cell(t cont){
        content = cont;
        next = NULL;
    }

    ~Cell(){
        //content = NULL;
        next = NULL;
    }

    t getContent(){
        return content;
    }
    void setContent(t cont){
        content = cont;
    }
    Cell<t> getNext(){
        return *next;
    }
    void setNext(Cell<t> nextcell){
        next = &nextcell;
    }

    operator std::string() const {
        return std::to_string(content);
    }

    bool equal(Cell<t> other){
        return content == other.content && next == other.next;
    }

};