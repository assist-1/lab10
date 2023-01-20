//
// Created by 79875 on 20.01.2023.
//

#ifndef LABA_PL_10_HEADER_HPP
#define LABA_PL_10_HEADER_HPP

#include <iostream>

using std::cout;

template<class T>
class MyPriorityQueue {
public:
    size_t Size = 0;

    virtual void push(T) = 0;

    virtual void pop() = 0;


    virtual T peek() = 0;

    size_t size();
};

template<typename T>
class MyPriorityQueueMax : public MyPriorityQueue<T> {
public:
    struct Node {
        T Data;
        Node *Next;
    };

    Node *Head;
    Node *Tail;

    void push(T);

    void pop();

    T peek();

    ~MyPriorityQueueMax();
};


template<typename T>
class MyPriorityQueueMin : public MyPriorityQueue<T> {
public:
    struct Node {
        T Data;
        Node *Next;
    };

    Node *Head;
    Node *Tail;

    void push(T);

    void pop();

    T peek();

    ~MyPriorityQueueMin();
};

template<typename T>
std::ostream &operator<<(std::ostream &, MyPriorityQueueMax<T> &);

template<typename T>
std::ostream &operator<<(std::ostream &, MyPriorityQueueMin<T> &);

#endif //LABA_PL_10_HEADER_HPP
