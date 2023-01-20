#include "header.hpp"

template<typename T>
size_t MyPriorityQueue<T>::size() {
    return Size;
}

/////////////////////Max
template<typename T>
void MyPriorityQueueMax<T>::push(T item) {
    if (this->Size == 0) {
        Node *newEl = new Node;
        newEl->Data = item;
        newEl->Next = nullptr;

        Head = newEl;
        Tail = newEl;
    } else if (this->Size == 1) {
        if (item > Head->Data) {
            Node *newEl = new Node;
            newEl->Data = item;

            Head = newEl;
            Head->Next = Tail;

        } else {
            Node *newEl = new Node;
            newEl->Data = item;
            newEl->Next = nullptr;

            Tail = newEl;
            Head->Next = Tail;
        }
    } else {
        Node *newEl = new Node;
        newEl->Data = item;

        Node *tmpEl = Head;

        Head = newEl;
        Head->Next = tmpEl;

        Node *tmpEl2 = Head;

        while (tmpEl2->Next != nullptr) {
            if (tmpEl2->Data < tmpEl2->Next->Data) {
                std::swap(tmpEl2->Data, tmpEl2->Next->Data);
            }
            tmpEl2 = tmpEl2->Next;
        }
    }
    this->Size++;
}

template<typename T>
T MyPriorityQueueMax<T>::pop() {
    if (this->Size == 1) {
        this->Size--;

        T res = Head->Data;

        delete Head;

        Tail = nullptr;
        Head = nullptr;
        return res;
    } else if (this->Size > 1) {
        this->Size--;
        Node *tmpEl = Head->Next;

        T res = Head->Data;


        delete Head;
        Head = tmpEl;
        return res;
    }
    std::cerr<<"ERROR";
    return 0;
}

template<typename T>
T MyPriorityQueueMax<T>::peek() {
    if (this->Size > 0) {
        return Head->Data;
    }
    std::cerr << "\nERROR\n";
    return 0;
}

////////////////Min

template<typename T>
void MyPriorityQueueMin<T>::push(T item) {
    if (this->Size == 0) {
        Node *newEl = new Node;
        newEl->Data = item;
        newEl->Next = nullptr;

        Head = newEl;
        Tail = newEl;
    } else if (this->Size == 1) {
        if (item < Head->Data) {
            Node *newEl = new Node;
            newEl->Data = item;

            Head = newEl;
            Head->Next = Tail;

        } else {
            Node *newEl = new Node;
            newEl->Data = item;
            newEl->Next = nullptr;

            Tail = newEl;
            Head->Next = Tail;
        }
    } else {
        Node *newEl = new Node;
        newEl->Data = item;

        Node *tmpEl = Head;

        Head = newEl;
        Head->Next = tmpEl;

        Node *tmpEl2 = Head;

        while (tmpEl2->Next != nullptr) {
            if (tmpEl2->Data > tmpEl2->Next->Data) {
                std::swap(tmpEl2->Data, tmpEl2->Next->Data);
            }
            tmpEl2 = tmpEl2->Next;
        }
    }
    this->Size++;
}

template<typename T>
T MyPriorityQueueMin<T>::pop() {
    if (this->Size == 1) {
        this->Size--;

        T res = Head->Data;

        delete Head;

        Tail = nullptr;
        Head = nullptr;
        return res;
    } else if (this->Size > 1) {
        this->Size--;
        Node *tmpEl = Head->Next;

        T res = Head->Data;

        delete Head;
        Head = tmpEl;
        return res;
    }
    std::cerr<<"ERROR";
    return 0;
}

template<typename T>
T MyPriorityQueueMin<T>::peek() {
    if (this->Size > 0) {
        return Head->Data;
    }
    std::cerr << "\nERROR\n";
    return 0;
}

/////////////////////operator <<
template<typename T>
std::ostream &operator<<(std::ostream &strm, MyPriorityQueueMax<T> &X) {
    auto newEl = X.Head;
    strm << "[ ";
    while (newEl != nullptr) {
        strm << newEl->Data << " ";
        newEl = newEl->Next;
    }
    strm << "] size - "<< X.size()<<", peek - "<<X.peek()<<'\n';
    return strm;
}

template<typename T>
std::ostream &operator<<(std::ostream &strm, MyPriorityQueueMin<T> &X) {
    auto newEl = X.Head;
    strm << "[ ";
    while (newEl != nullptr) {
        strm << newEl->Data << " ";
        newEl = newEl->Next;
    }
    strm << "] size - "<< X.size()<<", peek - "<<X.peek()<<'\n';
    return strm;
}
/////////////////////////////////////////////////////

template<typename T>
MyPriorityQueueMax<T>::~MyPriorityQueueMax() {
    Node* tmpEl = Head->Next;
    delete Head;
    while (tmpEl != nullptr){
        Head = tmpEl;
        tmpEl = tmpEl->Next;
        delete Head;
    }
    Head = nullptr;
    Tail = nullptr;
}

template<typename T>
MyPriorityQueueMin<T>::~MyPriorityQueueMin() {
    Node* tmpEl = Head->Next;
    delete Head;
    while (tmpEl != nullptr){
        Head = tmpEl;
        tmpEl = tmpEl->Next;
        delete Head;
    }
    Head = nullptr;
    Tail = nullptr;
}
