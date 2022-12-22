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
    g.addDoubleEdge(&n7, &n4);
    

    std::cout << "Graph  :\n\n" << g.toString() << std::endl;


    std::cout << "is the Graph directed : " << g.isDirected() << std::endl;

    std::cout << "is the Graph strongly connected : " << g.isStronglyConnected() << std::endl;
    std::cout << "is the Graph weakly connected : " << g.isWeaklyConnected() << std::endl;
    std::cout << "is the graph full : " << g.isComplete() << std::endl;
    std::cout << "is the graph a cycle : " << g.isCycle() << std::endl;
    std::cout << "is the graph an undirected tree : " << g.isUndirectedTree() << std::endl;
    std::cout << "is n1 a weak articulation point : " << g.isWeakArticulation(&n1) << std::endl;
    std::cout << "is n2 a weak articulation point : " << g.isWeakArticulation(&n2) << std::endl;
    std::cout << "is n3 a weak articulation point : " << g.isWeakArticulation(&n3) << std::endl;
    std::cout << "is n4 a weak articulation point : " << g.isWeakArticulation(&n4) << std::endl;
    std::cout << "is n5 a weak articulation point : " << g.isWeakArticulation(&n5) << std::endl;
    std::cout << "is n6 a weak articulation point : " << g.isWeakArticulation(&n6) << std::endl;
    std::cout << "is n7 a weak articulation point : " << g.isWeakArticulation(&n7) << std::endl;

    return 0;
}