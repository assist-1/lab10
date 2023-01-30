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


    MyDeck();
    void push_back(T);
    void pop_back();
    void push_front(T);
    void pop_front();
    T back();
    T front();
    int size();
    std::ostream& printD(std::ostream&);
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
    MyDeck<T>::Elem* new_node = new MyDeck<T>::Elem();
    new_node->value = data;
    if (begin == NULL)
        end = begin = new_node;
    else {
        new_node->next = begin;
        begin->prev = new_node;
        begin = new_node;
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
    MyDeck<T>::Elem* new_node = new MyDeck<T>::Elem();
    new_node->value = data;
    if (begin == NULL)
        end = begin = new_node;
    else {
        new_node->prev = end;
        end->next = new_node;
        end = new_node;
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

template<typename T>
std::ostream& MyDeck<T>::printD(std::ostream& stream) {
    MyDeck<T>::Elem* curr = begin;
    if (sz == 0) {
        return stream;
    }
    while (true) {
        stream << curr->value << ' ';
        if (curr == end) {
            break;
        }
            
        curr = curr->next;
    }
    return stream;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, MyDeck<T> & d) {
    return d.printD(stream);
    
    /*MyDeck<T>::Elem* start = new MyDeck<T>::Elem();
    MyDeck<T>::Elem* finish = new MyDeck<T>::Elem();
    start = d.begin;
    finish = d.end;
    return stream << start->value << ' ' << finish->value << '\n';*/
}

#endif