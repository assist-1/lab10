#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include "mynode.h"
#include <iostream>
#include <string>

template<class T>
class BinaryTree {
    Node<T>* root;
public:
    BinaryTree<T>(Node<T>* root) : root(root) {};

    void push(Node<T>*);
    Node<T>* get_root() { return root; }
};

template<typename T>
void BinaryTree<T>::push(Node<T>* node) {
    Node<T>* current = root;
    while(true) {
        if (node->get_data() < current->get_data()) {
            if (current->get_left() == nullptr) {
                current->set_left(node);
                break;
            }
            else
                current = current->get_left();
        }
        else {
            if (current->get_right() == nullptr) {
                current->set_right(node);
                break;
            }
            else
                current = current->get_right();
        }
    }
    return;
}

template<typename T>
void printBT(const std::string& pref, Node<T>* node, bool is_left, std::ostream& out) {
    if (node != nullptr) {
        out << pref;
        out << (is_left ? "|---" : "|___");
        out << node << std::endl;
        
        printBT(pref + (is_left ? "|   " : "    "), node->get_left(), true, out);
        printBT(pref + (is_left ? "|   " : "    "), node->get_right(), false, out);
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& out, BinaryTree<T> tree) {
    printBT("", tree.get_root(), false, out);
    return out;
}

#endif