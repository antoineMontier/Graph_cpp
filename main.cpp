#include "Graph.cpp"

#include <iostream>

using namespace std;


int main(){

    Graph<double> g;
    Node<double> n1(1.0);
    Node<double> n2(2.0);
    Node<double> n3(3.0);
    Node<double> n4(4.0);
    Node<double> n5(5.0);
    Node<double> n6(6.0);
    Node<double> n7(7.0);

    g.addNode(&n1);
    g.addNode(&n2);
    g.addNode(&n3);
    g.addNode(&n4);
    g.addNode(&n5);
    g.addNode(&n6);
    g.addNode(&n7);


    g.addDoubleEdge(&n1, &n2);
    g.addDoubleEdge(&n1, &n4);
    g.addDoubleEdge(&n2, &n3);
    g.addDoubleEdge(&n2, &n7);
    g.addDoubleEdge(&n4, &n5);
    g.addDoubleEdge(&n4, &n6);
    

    std::cout << "Graph  :\n\n" << g.toString() << std::endl;


    std::cout << "is the Graph directed : " << g.isDirected() << std::endl;

    std::cout << "is the Graph strongly connected : " << g.isStronglyConnected() << std::endl;
    std::cout << "is the Graph weakly connected : " << g.isWeaklyConnected() << std::endl;
    std::cout << "is the graph full : " << g.isComplete() << std::endl;
    std::cout << "is the graph a cycle : " << g.isCycle() << std::endl;
    std::cout << "is the graph an undirected tree : " << g.isUndirectedTree() << std::endl;

    return 0;
}