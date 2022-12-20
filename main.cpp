#include "Graph.cpp"

#include <iostream>

using namespace std;


int main(){

    Graph<double> g;
    Node<double> n1(8.2);
    Node<double> n2(15.68);
    g.addNode(&n1);
    g.addNode(&n2);

    std::cout << "nodes number : " << g.countNodes() << std::endl;
    std::cout << "Graph :\n\n" << g.toString() << std::endl;


    return 0;
}