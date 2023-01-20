#include <iostream>
#include "mybinarytree.h"

int main() {
    Node<int>* r = new Node<int>(5);
    Node<int>* a = new Node<int>(10);
    Node<int>* b = new Node<int>(2);
    Node<int>* c = new Node<int>(3);
    Node<int>* d = new Node<int>(1);
    Node<int>* e = new Node<int>(4);

    BinaryTree<int> tree(r);
    
    tree.push(a);
    tree.push(b);
    tree.push(c);
    tree.push(d);
    tree.push(e);
    
    std::cout << tree << std::endl;

    return 0;
}
