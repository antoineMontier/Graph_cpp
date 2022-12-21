#include "Graph.cpp"

#include <iostream>

using namespace std;


int main(){

    Graph<double> g;
    Node<double> n1(8.2);
    Node<double> n2(15.68);
    Node<double> n3(-0.2);
    Node<double> n4(-7.2);
    g.addNode(&n1);
    g.addNode(&n2);
    g.addNode(&n3);
    g.addNode(&n4);
    g.addEdge(&n1, &n3);
    g.addEdge(&n1, &n4);
    g.addEdge(&n2, &n3);
    g.addEdge(&n2, &n1);
    g.addEdge(&n4, &n2);

    std::cout << "Graph  :\n\n" << g.toString() << std::endl;
    std::cout << "is the Graph simple : " << g.isDirected() << std::endl;
    std::cout << "is n1 connected to n1 ? : " << g.pathExists(&n1, &n1) << std::endl;
    std::cout << "is n1 connected to n2 ? : " << g.pathExists(&n1, &n2) << std::endl;
    std::cout << "is n1 connected to n3 ? : " << g.pathExists(&n1, &n3) << std::endl;
    std::cout << "is n1 connected to n4 ? : " << g.pathExists(&n1, &n4) << "\n" << std::endl;

    std::cout << "is n2 connected to n1 ? : " << g.pathExists(&n2, &n1) << std::endl;
    std::cout << "is n2 connected to n2 ? : " << g.pathExists(&n2, &n2) << std::endl;
    std::cout << "is n2 connected to n3 ? : " << g.pathExists(&n2, &n3) << std::endl;
    std::cout << "is n2 connected to n4 ? : " << g.pathExists(&n2, &n4) << "\n" << std::endl;

    std::cout << "is n3 connected to n1 ? : " << g.pathExists(&n3, &n1) << std::endl;
    std::cout << "is n3 connected to n2 ? : " << g.pathExists(&n3, &n2) << std::endl;
    std::cout << "is n3 connected to n3 ? : " << g.pathExists(&n3, &n3) << std::endl;
    std::cout << "is n3 connected to n4 ? : " << g.pathExists(&n3, &n4) << "\n" << std::endl;

    std::cout << "is n4 connected to n1 ? : " << g.pathExists(&n4, &n1) << std::endl;
    std::cout << "is n4 connected to n2 ? : " << g.pathExists(&n4, &n2) << std::endl;
    std::cout << "is n4 connected to n3 ? : " << g.pathExists(&n4, &n3) << std::endl;
    std::cout << "is n4 connected to n4 ? : " << g.pathExists(&n4, &n4) << "\n" << std::endl;


    return 0;
}