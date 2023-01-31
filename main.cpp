#include <iostream>
#include "BinaryTree.h"

int main() {
    BinaryTree<int> I;
    BinaryTree<int> D;
    int a = 12, b = 34, c =56;
    double x = 0.23, y = -92.45, z = 344.9, t = 1.2;

    I.Push(a);
    I.Push(b);
    I.Push(c);
    D.Push(x);
    D.Push(y);
    D.Push(z);
    D.Push(t);

    std::cout << I << std::endl;
    std::cout << D << std::endl;
}



