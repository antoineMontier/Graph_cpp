#include "LinkedList.cpp"

#include <iostream>

using namespace std;


int main(){
    LinkedList<int> list;
    list.pushTail(-400);
    list.push(8);
    list.pushTail(-230);
    list.push(9);
    list.push(-10);
    
    
    std::cout << list.toString() << " of size = "<<list.size()<< std::endl;

    list.bubbleSort([](int a,  int b){return a < b;});

    std::cout << list.toString() << " of size = "<<list.size()<< std::endl;

    std::cout << list.map([](int k){return k*k*k;}).toString() << " k*k*k "<< std::endl;

    std::cout << list.filter([](int k){return k % 2 == 0;}).toString() << " evens "<< std::endl;

    std::cout << list.reduce(1, [](int a, int b){return a * b;}) << " reduce "<< std::endl;

    return 0;
}