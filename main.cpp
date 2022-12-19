#include "Node.cpp"

#include <iostream>

using namespace std;


int main(){
    Node<int> node;
    node.set(5);

    Node<int> node2;
    node2.set(6);



    std::cout<<node.toString()<<endl;

    node.linkTo(&node2);

    std::cout<<node.toString()<<endl;


    return 0;
}