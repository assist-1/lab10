#include <iostream>


template<class ValueType>
class Element {
private:
    ValueType value;
    Element<ValueType> *next;
public:
    Element() : next(nullptr) {};

    explicit Element(ValueType v) : value(v), next(nullptr) {};

    explicit Element(ValueType v, Element<ValueType> *n) : value(v), next(n) {};

    explicit Element(Element<ValueType> *e) : value(e->get_value()), next(e->get_next()) {};

    void set_next(Element<ValueType> *n) {
        this->next = n;
    }

    Element *get_next() {
        return next;
    }

    ValueType get_value() {
        return value;
    }
};


template<class ListType>
class List {
protected:
    Element<ListType> *first;
    int len;
public:
    List() {
        Element<ListType> empty;
        first = &empty;
        len = 0;
    }

    List(Element<ListType> *e) {
        first = e;
        len = 1;
    }

    ~List() {
        for (int i = 0; i < len; ++i) {
            Element<ListType> *newFirstElement = this->first->get_next();
            delete this->first;
            this->first = newFirstElement;
        }
    }

    int size() {
        return len;
    }

    void print() {
        Element<ListType> a = *first;
        std::cout << "{ ";
        for (int i = 0; i < len; i++) {
            std::cout << i << ": " << a.get_value() << ", ";
            if (i < len - 1) a = *a.get_next();
        }
        std::cout << "}\n";
    }
};


template<class QueueType>
class MyPriorityQueue : public List<QueueType> {
public:
    void push(Element<QueueType> *newElement) {
        Element<QueueType> *currentElement = this->first;
        while (newElement->get_value() <= currentElement->get_value()) {
            if (newElement->get_value() > currentElement->get_next()->get_value()) {
                newElement->set_next(currentElement->get_next());
                currentElement->set_next(newElement);
                ++this->len;
                break;
            }
            currentElement = currentElement->get_next();
        }
    }

    QueueType pop() {
        QueueType value = this->first->get_value();
        Element<QueueType> *newFirstElement = this->first->get_next();
        delete this->first;
        this->first = newFirstElement;
        --this->len;
        return value;
    }

    QueueType peek() {
        return this->first->get_value();
    }
};


template<class T>
std::ostream &operator<<(std::ostream &outStream, MyPriorityQueue<T> *newQueue) {
    std::cout.rdbuf(outStream.rdbuf());
    newQueue->print();
    return outStream;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
