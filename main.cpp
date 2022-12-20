#include "Graph.cpp"

#include <iostream>

using namespace std;


int main(){

    Graph<double> g;

    std::cout << "nodes number : " << g.countNodes() << std::endl;
    std::cout << "Graph :\n\n" << g.toString() << std::endl;


    return 0;
}