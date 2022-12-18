
#include "LinkedList.cpp"

#include <iostream>

using namespace std;


int main(){
    LinkedList<int> list;
    list.pushTail(-400);
    std::cout << list.toString() << std::endl;
    list.push(8);
    list.pushTail(-230);
    list.push(9);
    list.push(10);
    
    
    std::cout << list.toString() << std::endl;

    std::cout << list.pop() << std::endl;
    std::cout << list.toString() << std::endl;

    std::cout << list.pop() << std::endl;
    std::cout << list.toString() << std::endl;

    std::cout << list.pop() << std::endl;
    std::cout << list.toString() << std::endl;
    
    std::cout << list.pop() << std::endl;
    std::cout << list.toString() << std::endl;


    return 0;
}