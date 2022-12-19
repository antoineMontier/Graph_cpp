#include "Node.cpp"

#include <iostream>

using namespace std;


int main(){
    Node<double> node1;
    node1.set(1.0);

    Node<double> node2;
    node2.set(2.0);

    Node<double> node3;
    node3.set(3.0);

    Node<double> node4;
    node4.set(4.0);

    Node<double> node5;
    node5.set(5.0);

    Node<double> node6;
    node6.set(6.0);



    node1.linkTo(&node2);
    node1.linkTo(&node3);
    node2.linkTo(&node4);
    node3.linkTo(&node5);
    node4.linkTo(&node2);
    node2.linkTo(&node2);

    node1.unlink(&node3);



    std::cout   <<  node1.toString() <<    " neightbours number : "  <<    node1.neighboursCount()  <<  endl;
    std::cout   <<  node2.toString() <<    " neightbours number : "  <<    node2.neighboursCount()  <<  endl;
    std::cout   <<  node3.toString() <<    " neightbours number : "  <<    node3.neighboursCount()  <<  endl;
    std::cout   <<  node4.toString() <<    " neightbours number : "  <<    node4.neighboursCount()  <<  endl;
    std::cout   <<  node5.toString() <<    " neightbours number : "  <<    node5.neighboursCount()  <<  endl;
    std::cout   <<  node6.toString() <<    " neightbours number : "  <<    node6.neighboursCount()  <<  endl;

    std::cout  << "no " <<  node4.isLinked(&node1)  <<  endl;
    std::cout  << "yes " <<  node4.isLinked(&node2)  <<  endl;


    return 0;
}