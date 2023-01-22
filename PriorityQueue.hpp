#ifndef MYPRIORITYQUEUE_PRIORITYQUEUE_HPP
#define MYPRIORITYQUEUE_PRIORITYQUEUE_HPP

#include <iostream>

///шаблонный класс Priority Queue
///первым из очереди выходит элемент с наименьшим приоритетом(1,2,3...), вошедший первым

template<class Type>
class Queue {
public:
    struct Node {
        Node *Next = nullptr;
        Type Data;
        int Priority;
    };
private:
    // Указатель на первый элемент очереди.
    Node *Head = nullptr;
    // Указатель на последний элемент очереди.
    Node *Tail = nullptr;
public:
    Queue() {
        Head = nullptr;
        Tail = nullptr;
    }

    void Push(Type value, int priority) {
        Queue<Type>::Node *newElement = new Queue<Type>::Node;
        newElement->Data = value;
        newElement->Priority = priority;
        if (Head == nullptr) {
            Head = newElement;
            Tail = newElement;
        } else if ((Get_size()) == 1) {
            Head = newElement;
            Head->Next = Tail;
        } else {
            newElement->Next = Head;
            Head = newElement;
        }
        if (Get_size() > 1) {
            Queue<Type>::Node *tmp = Head;
            while (tmp->Next != nullptr) {
                if ((tmp->Priority) >= (tmp->Next->Priority)) {
                    Type tempData = tmp->Data;
                    Type tempPriority = tmp->Priority;
                    tmp->Data = tmp->Next->Data;
                    tmp->Priority = tmp->Next->Priority;
                    tmp->Next->Data = tempData;
                    tmp->Next->Priority = tempPriority;
                }
                tmp = tmp->Next;
            }
        }
    }

    void Pop() {
        if (Head == nullptr) {
            return;
        } else {
            Queue<Type>::Node *after = Head->Next;
            delete Head;
            Head = after;
        }
    }

    size_t Get_size() {
        size_t i = 0;
        Queue<Type>::Node *element = Head;
        while (element->Next != nullptr) {
            i++;
            element = element->Next;
        }
        return ++i;
    }

    Type Peek() {
        if (this->Get_size() != 0) {
            return Head->Data;
        }
        std::cerr << "Error!" << std::endl;
        exit(1);
    }

    Node *Get_head() {
        return Head;
    }

    Node *Get_Tail() {
        return Tail;
    }


    ~Queue() {
        while (Head != nullptr) {
            Queue<Type>::Node *iter = Head->Next;
            delete Head;
            Head = iter;
        }
        delete Head;
        Head = nullptr;
        Tail = nullptr;
    }
};


#endif //MYPRIORITYQUEUE_PRIORITYQUEUE_HPP
