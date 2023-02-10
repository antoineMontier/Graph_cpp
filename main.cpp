#include "Graph.cpp"

#include <iostream>

using namespace std;


int main(){

    LinkedList<int> k;

    for(int i=0; i<20 ; i++)
        k.push(i*i*i % (i + i + 1));

    std::cout << k.toString() << std::endl;

    k.swap(11, 7);

    std::cout << k.toString() << std::endl;








    /*
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
    std::cout << "is n1 a strong articulation point : " << g.isStrongArticulation(&n1) << std::endl;
    std::cout << "is n2 a strong articulation point : " << g.isStrongArticulation(&n2) << std::endl;
    std::cout << "is n3 a strong articulation point : " << g.isStrongArticulation(&n3) << std::endl;
    std::cout << "is n4 a strong articulation point : " << g.isStrongArticulation(&n4) << std::endl;
    std::cout << "is n5 a strong articulation point : " << g.isStrongArticulation(&n5) << std::endl;
    std::cout << "is n6 a strong articulation point : " << g.isStrongArticulation(&n6) << std::endl;
    std::cout << "is n7 a strong articulation point : " << g.isStrongArticulation(&n7) << std::endl;
    */


    return 0;
}