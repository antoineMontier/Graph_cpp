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
    g.addEdge(&n1, &n2);
    g.addEdge(&n1, &n3);
    g.removeEdge(&n1, &n3);
    g.removeEdge(&n1, &n2);

    std::cout << "nodes number : " << g.countNodes() << std::endl;
    std::cout << "Graph :\n\n" << g.toString() << std::endl;
    std::cout << "yes " << g.isNodePresent(&n1) << std::endl;
    std::cout << "no " << g.isNodePresent(&n3) << std::endl;


    return 0;
}