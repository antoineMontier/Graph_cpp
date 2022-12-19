#include "Node.cpp"

#include <iostream>

using namespace std;


int main(){
    Node<int> node;
    std::cout<<node.toString()<<endl;
    
    node.set(5);
    std::cout<<node.toString()<<endl;
    
    std::cout<<node.get()<<endl;
    std::cout<<node.toString()<<endl;
    
    return 0;
}