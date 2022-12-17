
#include "LinkedList.cpp"

#include <iostream>

using namespace std;


int main(){
    Cell<int> c(5);
    LinkedList<int> list(c);
    std::cout << list.toString() << std::endl;
    return 0;
}