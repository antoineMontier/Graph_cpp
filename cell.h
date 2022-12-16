#ifndef CELL_H
#define CELL_H

using namespace std;

template <class t> class Cell{
    
    private:
        t content;
        Cell<t> *next;

    public:
        Cell(t cont, Cell<t> nextcell);

        Cell();

        Cell(t cont);

        ~Cell();

        t getContent();

        void setContent(t cont);

        Cell<t> getNext();

        void setNext(Cell<t> nextcell);

        operator std::string() const {return std::to_string(content);}

        bool equal(Cell<t> other);

};

#endif