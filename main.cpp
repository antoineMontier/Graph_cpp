#include "cell.h"
#include "cell.cpp"

#include <iostream>

using namespace std;


int main(){
    Cell<int> c(0);
    std::cout << "[0] " << c.toString() << endl;
    Cell<int> k(6);
    std::cout << "[6] " << k.toString() << endl;
    std::cout << "0 " << k.equal(c) << endl;
    k.setNext(&c);
    std::cout << "1 " << k.getNext().equal(c) << endl;
    std::cout << "[0] " << k.getNext().toString() <<endl;
    c.setContent(-120);
    std::cout << "[-120] " << c.toString() << endl;
    std::cout << "[-120] " << k.getNext().toString() <<endl;
    std::cout << "1 " << k.hasNext() << endl;
    std::cout << "0 " << c.hasNext() << endl;
    std::cout << "0 " << c.getNext().toString() << endl;
    return 0;
}