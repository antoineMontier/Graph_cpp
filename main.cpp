
#include "LinkedList.cpp"

#include <iostream>

using namespace std;


int main(){
    LinkedList<int> list;
    list.pushTail(-400);
    list.push(8);
    list.pushTail(-230);
    list.push(9);
    list.push(10);
    
    
    std::cout << list.toString() << " of size = "<<list.size()<< std::endl;
    for(int i = 0; i < list.size() ; i++)
        std::cout <<"i = " << i << "  "<< list.toString() << " || " << list.pop(i)<< " || " <<list.size()<< std::endl;

    return 0;
}