#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class Deck{
private:

    class Node
    {
    public:
        Node *prev;
        Node *next;
        T data;
        explicit Node(T data = T(), Node *prev = nullptr)
        {
            this -> data = data;
            this -> next = next;
            this -> prev = prev;
        }
    };
    int Length;
    Node *head;
    Node *tail;

public:
    Deck();
    ~Deck();

    void push_back(T data);
    void push_front(T data);
    void pop_front();
    void pop_back();
    int get_size(){return Length;};
    const Node* get_head() {return head;}
};

template <typename T>
Deck<T>::Deck()
{
    Length = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
Deck<T>::~Deck()
{
    cout << "Деструктор вызван." << endl;
    while ((head != nullptr) && (tail != nullptr))
    {
        pop_front();
    }
}

template <typename T>
void Deck<T>::push_back(T data)
{
    Node *temp = new Node(data);
    temp -> next = tail;
    if (tail != nullptr)
    {
        tail -> prev = temp;
    }
    if (head == nullptr)
    {
        head = temp;
    }
    tail = temp;
    Length++;
}

template <typename T>
void Deck<T>::push_front(T data)
{
    Node *temp = new Node(data);
    temp -> prev = head;
    if (head != nullptr)
    {
        head -> next = temp;
    }
    if (tail == nullptr)
    {
        tail = temp;
    }
    head = temp;
    Length++;
}

template <typename T>
void Deck<T>::pop_back()
{
    if (tail == nullptr) return;

    Node* temp = tail -> next;
    if (temp != nullptr)
    {
        temp -> prev = nullptr;
    }
    else
    {
         head = nullptr;
    }
    delete tail;
    tail = temp;
    Length--;
}

template <typename T>
void Deck<T>::pop_front()
{
    if (head == nullptr) return;

    Node* temp = head -> prev;
    if (temp != nullptr)
    {
        temp -> next = nullptr; // Тут пиздец какой-то
    }
    else
    {
        tail = nullptr;
    }
    delete head;
    head = temp;
    Length--;
}

template <typename T>
std::ostream& operator << (std::ostream& os, Deck<T>* dck) {
    auto temp = dck->get_head();
    os << "Deck:" << endl;
    int iter = 0;
    while (temp != nullptr) {
        os << "[" << iter << "]" << " = " << temp->data << endl;
        temp = temp->prev;
        iter += 1;
    }
    return os;
}

int main() {
    Deck<int>* dck = new Deck<int>;
    dck->push_front(10);
    dck->push_front(15);
    dck->push_back(5);
    dck->push_back(123);
    dck->pop_front();
    dck->pop_back();
    cout << "Размер Deck = " << dck->get_size() << endl;
    cout << dck;
    delete dck;

    cout << endl;

    Deck<char>* ChDck = new Deck<char>;
    ChDck->push_front('G');
    ChDck->push_front('F');
    ChDck->push_front('E');
    ChDck->push_front('D');
    ChDck->push_front('C');
    ChDck->push_front('B');
    ChDck->push_front('A');
    ChDck->push_back('H');
    ChDck->push_back('I');
    ChDck->push_back('J');
    ChDck->pop_front();
    ChDck->pop_back();
    cout << "Размер Deck = " << ChDck->get_size() << endl;
    cout << ChDck;
    delete ChDck;
}
