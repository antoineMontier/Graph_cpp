#include "cell.h"
#include "cell.cpp"

#include <iostream>

using namespace std;


int main(){
    Cell<int> c(0);
    std::cout << c.toString() << endl;

    return 0;
}