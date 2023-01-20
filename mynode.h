#ifndef NODE_H_
#define NODE_H_

#include <iostream>

template<class T>
class Node {
    T         data;
    Node<T>*  left;
    Node<T>* right;
public:
    Node<T>(T data)        : data(data),             left(nullptr),        right(nullptr) {};
    Node<T>(Node<T>* node) : data(node->get_data()), left(node->get_left), right(node->get_right) {};

    void     set_right(Node<T>* n) { right = n;    }
    Node<T>* get_right()           { return right; }

    void     set_left(Node<T>* n)  { left = n;    }
    Node<T>* get_left()            { return left; }

    void set_data(T d) { data = d;    }
    T    get_data()    { return data; }
};

template<typename T>
std::ostream& operator<<(std::ostream& out, Node<T>* node) {
    out << node->get_data();
    return out;
}

#endif