#ifndef MYDECK
#define MYDECK

template <typename T>
class MyDeck {
public:
    struct Elem {
        T value;
        Elem *prev;
        Elem *next;
        Elem() : value(0), prev(nullptr), next(nullptr) {};
    };

    int sz;
    Elem *begin;
    Elem *end;

public:
    MyDeck();
    void push_back(T);
    void pop_back();
    void push_front(T);
    void pop_front();
    T back();
    T front();
    int size();
};

template <typename T>
MyDeck<T>::MyDeck() {
    sz = 0;
    begin = nullptr;
    end = nullptr;
}

template <typename T>
int MyDeck<T>::size() {
    return sz;
}

template <typename T>
void MyDeck<T>::push_front(T data) {
    MyDeck<T>::Elem* temp = new MyDeck<T>::Elem();
    temp->value = data;
    temp->prev = nullptr;
    begin = temp;
    if (sz == 0) {
        end = temp;
    }
    ++sz;
};

template <typename T>
void MyDeck<T>::pop_front() {
    if (sz == 0) {
        std::cerr << "This deck is empty!";
        exit(1);
    }
    else {
        begin = begin->next;
        begin->prev = nullptr;
        --sz;
    }
};

template <typename T>
T MyDeck<T>::front() {
    if (sz == 0) {
        std::cerr << "This deck is empty!";
        exit(1);
    }
    else {
        return begin->value;
    }
}

template <typename T>
void MyDeck<T>::push_back(T data) {
    MyDeck<T>::Elem* temp = new MyDeck<T>::Elem();
    temp->value = data;
    temp->next = nullptr;
    end = temp;
    if (sz == 0) {
        end = temp;
    }
    ++sz;
};

template <typename T>
void MyDeck<T>::pop_back() {
    if (sz == 0) {
        std::cerr << "This deck is empty!";
        exit(1);
    }
    else {
        end = end->prev;
        end->next = nullptr;
        --sz;
    }
};


template <typename T>
T MyDeck<T>::back() {
    if (sz == 0) {
        std::cerr << "This deck is empty!";
        exit(1);
    }
    else {
        return end->value;
    }
};

#endif