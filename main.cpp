#include "Graph.cpp"

#include <iostream>

using namespace std;


int main(){

    Graph<double> g;
    Node<double> n1(8.2);
    Node<double> n2(15.68);
    Node<double> n3(-0.2);
    Node<double> n4(-7.2);
    Node<double> n5(12.36);
    Node<double> n6(1.0);
    Node<double> n7(8.9);

    g.addNode(&n1);
    //g.addNode(&n2);
    g.addNode(&n3);
    g.addNode(&n4);
    g.addNode(&n5);
    g.addNode(&n6);
    g.addNode(&n7);


    g.addEdge(&n1, &n3);
    g.addEdge(&n1, &n4);
    g.addEdge(&n2, &n3);
    g.addEdge(&n4, &n1);
    g.addEdge(&n4, &n7);
    g.addEdge(&n7, &n6);
    g.addEdge(&n5, &n6);
    g.addEdge(&n6, &n4);
    g.addEdge(&n3, &n5);

    std::cout << "Graph  :\n\n" << g.toString() << std::endl;


    std::cout << "is the Graph directed : " << g.isDirected() << std::endl;

    std::cout << "is the Graph strongly connected : " << g.isStronglyConnected() << std::endl;


    return 0;
}