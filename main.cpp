#include "Graph.cpp"

#include <iostream>

using namespace std;


int main(){

    Graph<double> g;
    Node<double> n1(8.2);
    Node<double> n2(15.68);
    Node<double> n3(-0.2);
    g.addNode(&n1);
    g.addNode(&n2);
    g.addNode(&n3);
    g.addEdge(&n1, &n3);
    g.addEdge(&n1, &n3);
    g.addEdge(&n3, &n1);

    std::cout << "Graph  :\n\n" << g.toString() << std::endl;
    std::cout << "is the Graph simple : " << g.isDirected() << std::endl;
    std::cout << "is n1 connected to n2 ? : " << g.pathExists(&n1, &n2) << std::endl;


    return 0;
}