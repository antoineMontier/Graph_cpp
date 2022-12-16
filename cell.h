#ifndef CELL_H
#define CELL_H

using namespace std;

template <class T>
class Cell{
    
    private:
        T content;
        Cell<T> *next;

    public:
        Cell(T cont, Cell<T> nextcell);

        Cell();

        Cell(T cont);

        ~Cell();

        T getContent();

        void setContent(T cont);

        Cell<T> getNext();

        void setNext(Cell<T> nextcell);

        operator std::string() const;

        bool equal(Cell<T> other);

};

#endif