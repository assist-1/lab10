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
        first = nullptr;
        len = 0;
    }

    explicit List(Element<ListType> *e) {
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
        Element<ListType> *a = this->first;
        std::cout << "{ ";
        for (int i = 0; i < this->len; i++) {
            std::cout << i << ": " << a->get_value();
            if (i < this->len - 1) {
                std::cout << ", ";
            }
            if (i < this->len - 1) {
                a = a->get_next();
            }
        }
        std::cout << "}\n";
    }

    virtual void push(ListType newItem) {
        auto newElement = new Element<ListType>(newItem);
        if (this->first == nullptr) {
            this->first = newElement;
        } else {
            Element<ListType> *currentElement = this->first;
            for (int i = 0; i < this->len - 1; ++i) {
                currentElement = currentElement->get_next();
            }
            currentElement->set_next(newElement);
            ++this->len;
        }
    }

};


template<class QueueType>
class MyPriorityQueue : public List<QueueType> {
public:
    void push(QueueType newItem) override {
       auto newElement = new Element<QueueType>(newItem);
        if (this->first == nullptr) {
            this->first = newElement;
            this->len = 1;
        }
        if (newElement->get_value() > this->first->get_value()) {
            newElement->set_next(this->first);
            this->first = newElement;
            ++this->len;
        } else {
            Element<QueueType> *currentElement = this->first;
            for (int i = 0; i < this->len - 1; ++i) {
                if (currentElement->get_next() != nullptr &&
                    newElement->get_value() > currentElement->get_next()->get_value()) {
                    newElement->set_next(currentElement->get_next());
                    currentElement->set_next(newElement);
                    ++this->len;
                    break;
                }
                currentElement = currentElement->get_next();
            }
            if (currentElement->get_next() == nullptr) {
                currentElement->set_next(newElement);
            }
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
    auto test = new MyPriorityQueue<int>;
    test->push(1);
    test->push(9);
    test->push(8);
    std::cout << "First element of the priority queue: " << test->peek() << "\n";
    std::cout << "Queue: " << test;
    int a = test->pop();
    std::cout << "First element (" << a << ") was poped and now the queue is " << test;

    delete test;

    return 0;
}
