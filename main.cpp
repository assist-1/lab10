#include <iostream>
#include "PriorityQueue.hpp"

template<typename Type>
std::ostream &operator<<(std::ostream &stream, Queue<Type> &a) {
    auto iter = a.Get_head();
    stream << "Queue - {";
    while (iter != nullptr) {
        stream << " " << iter->Data;
        iter = iter->Next;
    }
    stream << " } - Size of this queue is " << a.Get_size();
    return stream;
}

int main() {
    Queue<int> a;
    a.Push(15, 6);
    a.Push(17, 7);
    a.Push(18, 9);
    a.Push(19, 6);
    a.Push(30, 7);
    a.Push(20, 7);
    a.Pop();
    std::cout << a << std::endl;
    std::cout << "Peek queue - " << a.Peek() << std::endl;

    Queue<char> b;
    b.Push('5', 6);
    b.Push('7', 7);
    b.Push('8', 9);
    b.Push('9', 6);
    b.Push('0', 7);
    b.Push('2', 7);
    b.Pop();
    std::cout << b << std::endl;
    std::cout << "Peek queue - " << b.Peek() << std::endl;
}