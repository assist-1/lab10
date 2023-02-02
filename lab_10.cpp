

#include <iostream>

template<class T> class Node {
public:
    T data;
    Node* prev, * next;
public:
    Node(T data) {
        this->data = data;
        this->prev = this->next = nullptr;

    }
};

template<class T> class my_deck {
public:
    int size;
    Node<T>* head;
    Node<T>* tail;
public:
    my_deck() {
        head = tail = nullptr;
        size = 0;
    }
    Node<T>* push_front(T data) {
        Node<T>* ptr = new Node<T>(data);
        ptr->next = head;
        if (head != nullptr) {
            head->prev = ptr;
        }
        if (tail == nullptr) {
            tail = ptr;
        }
        head = ptr;
        size++;
        return ptr;
    }
    Node<T>* push_back(T data) {
        Node<T>* ptr = new Node<T>(data);
        ptr->prev = tail;
        if (tail != nullptr) {
            tail->next = ptr;
        }
        if (head == nullptr) {
            head = ptr;
        }
        tail = ptr;
        size++;
        return ptr;
    }
    void pop_front() {
        if (head == nullptr) return;
        Node<T>* ptr = head->next;
        if (ptr != nullptr) {
            ptr->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete head;
        size--;
        head = ptr;
    }
    void pop_back() {
        if (tail == nullptr) return;
        Node<T>* ptr = tail->prev;
        if (ptr != nullptr) {
            ptr->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete tail;
        size--;
        tail = ptr;
    }
    T get_first() {
        return head->data;
    }
    T get_last() {
        return tail->data;
    }
    int get_size() {
        return size;
    }

};
template<typename T>
std::ostream& operator<<(std::ostream& a, my_deck<T>& deck) {
    Node<T>* c = deck.head;
    if (!deck.size)
        return a;
    do {
        std::cout << c->data << ' ';
        c = c->next;
    } while (c != nullptr);
    return a;
}

int main()
{
    my_deck<float> deck;
    deck.push_front(3.14f);
    deck.push_back(5.08f);
    deck.push_back(6.99f);
    deck.push_front(17.844f);
    std::cout << deck << std::endl;
    std::cout << deck.get_first() << " " << deck.get_last() << std::endl;
    deck.pop_front();
    std::cout << deck.get_first() << std::endl;
    std::cout << deck.get_size()<<std::endl;
 
    std::cout << deck << std::endl;

}

