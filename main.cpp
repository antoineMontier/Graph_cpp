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
    g.addNode(&n2);
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


    std::cout << "is the Graph simple : " << g.isDirected() << std::endl;
    std::cout << "is n1 connected to n1 ? : " << g.pathExists(&n1, &n1) << std::endl;
    std::cout << "is n1 connected to n2 ? : " << g.pathExists(&n1, &n2) << std::endl;
    std::cout << "is n1 connected to n3 ? : " << g.pathExists(&n1, &n3) << std::endl;
    std::cout << "is n1 connected to n4 ? : " << g.pathExists(&n1, &n4) << std::endl;
    std::cout << "is n1 connected to n5 ? : " << g.pathExists(&n1, &n5) << std::endl;
    std::cout << "is n1 connected to n6 ? : " << g.pathExists(&n1, &n6) << std::endl;
    std::cout << "is n1 connected to n7 ? : " << g.pathExists(&n1, &n7) << "\n" << std::endl;

    std::cout << "is n2 connected to n1 ? : " << g.pathExists(&n2, &n1) << std::endl;
    std::cout << "is n2 connected to n2 ? : " << g.pathExists(&n2, &n2) << std::endl;
    std::cout << "is n2 connected to n3 ? : " << g.pathExists(&n2, &n3) << std::endl;
    std::cout << "is n2 connected to n4 ? : " << g.pathExists(&n2, &n4) << std::endl;
    std::cout << "is n2 connected to n5 ? : " << g.pathExists(&n2, &n5) << std::endl;
    std::cout << "is n2 connected to n6 ? : " << g.pathExists(&n2, &n6) << std::endl;
    std::cout << "is n2 connected to n7 ? : " << g.pathExists(&n2, &n7) << "\n" << std::endl;

    std::cout << "is n3 connected to n1 ? : " << g.pathExists(&n3, &n1) << std::endl;
    std::cout << "is n3 connected to n2 ? : " << g.pathExists(&n3, &n2) << std::endl;
    std::cout << "is n3 connected to n3 ? : " << g.pathExists(&n3, &n3) << std::endl;
    std::cout << "is n3 connected to n4 ? : " << g.pathExists(&n3, &n4) << std::endl;
    std::cout << "is n3 connected to n5 ? : " << g.pathExists(&n3, &n5) << std::endl;
    std::cout << "is n3 connected to n6 ? : " << g.pathExists(&n3, &n6) << std::endl;
    std::cout << "is n3 connected to n7 ? : " << g.pathExists(&n3, &n7) << "\n" << std::endl;

    std::cout << "is n4 connected to n1 ? : " << g.pathExists(&n4, &n1) << std::endl;
    std::cout << "is n4 connected to n2 ? : " << g.pathExists(&n4, &n2) << std::endl;
    std::cout << "is n4 connected to n3 ? : " << g.pathExists(&n4, &n3) << std::endl;
    std::cout << "is n4 connected to n4 ? : " << g.pathExists(&n4, &n4) << std::endl;
    std::cout << "is n4 connected to n5 ? : " << g.pathExists(&n4, &n5) << std::endl;
    std::cout << "is n4 connected to n6 ? : " << g.pathExists(&n4, &n6) << std::endl;
    std::cout << "is n4 connected to n7 ? : " << g.pathExists(&n4, &n7) << "\n" << std::endl;

    std::cout << "is n5 connected to n1 ? : " << g.pathExists(&n5, &n1) << std::endl;
    std::cout << "is n5 connected to n2 ? : " << g.pathExists(&n5, &n2) << std::endl;
    std::cout << "is n5 connected to n3 ? : " << g.pathExists(&n5, &n3) << std::endl;
    std::cout << "is n5 connected to n4 ? : " << g.pathExists(&n5, &n4) << std::endl;
    std::cout << "is n5 connected to n5 ? : " << g.pathExists(&n5, &n5) << std::endl;
    std::cout << "is n5 connected to n6 ? : " << g.pathExists(&n5, &n6) << std::endl;
    std::cout << "is n5 connected to n7 ? : " << g.pathExists(&n5, &n7) << "\n" << std::endl;

    std::cout << "is n6 connected to n1 ? : " << g.pathExists(&n6, &n1) << std::endl;
    std::cout << "is n6 connected to n2 ? : " << g.pathExists(&n6, &n2) << std::endl;
    std::cout << "is n6 connected to n3 ? : " << g.pathExists(&n6, &n3) << std::endl;
    std::cout << "is n6 connected to n4 ? : " << g.pathExists(&n6, &n4) << std::endl;
    std::cout << "is n6 connected to n5 ? : " << g.pathExists(&n6, &n5) << std::endl;
    std::cout << "is n6 connected to n6 ? : " << g.pathExists(&n6, &n6) << std::endl;
    std::cout << "is n6 connected to n7 ? : " << g.pathExists(&n6, &n7) << "\n" << std::endl;

    std::cout << "is n7 connected to n1 ? : " << g.pathExists(&n7, &n1) << std::endl;
    std::cout << "is n7 connected to n2 ? : " << g.pathExists(&n7, &n2) << std::endl;
    std::cout << "is n7 connected to n3 ? : " << g.pathExists(&n7, &n3) << std::endl;
    std::cout << "is n7 connected to n4 ? : " << g.pathExists(&n7, &n4) << std::endl;
    std::cout << "is n7 connected to n5 ? : " << g.pathExists(&n7, &n5) << std::endl;
    std::cout << "is n7 connected to n6 ? : " << g.pathExists(&n7, &n6) << std::endl;
    std::cout << "is n7 connected to n7 ? : " << g.pathExists(&n7, &n7) << "\n" << std::endl;


    return 0;
}