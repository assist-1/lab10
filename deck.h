template <typename T>
class Deck
{
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int size = 0;
// tail -> 0-----0 <- head
public:
    ~Deck();
    void push_back(T);
    void push_front(T);
    void pop_back();
    void pop_front();
    T get_back();
    T get_front();
    int get_size();
    friend std::ostream& operator <<(std::ostream& os, Deck<T>& deck)
    {
        int lena = deck.get_size();
        Node<T>* tail_pr = deck.tail;
        for (int i = 0; i < lena; i++)
        {
            os << tail_pr->value << " ";
            tail_pr = tail_pr->pr_head;
        }
        return os;
    }
};


template <typename T>
Deck<T>::~Deck()
{
    while(size != 0) pop_front();
}

template <typename T>
void Deck<T>::push_back(T item)
{
    Node<T>* new_tail = new Node<T>(item);
    if (size == 0)
    {
        tail = new_tail;
        head = new_tail;
    }
    if(size == 1)
    {
        tail = new_tail;
        tail->pr_head = head;
        head->pr_tail = tail;
    }
    else
    {
        Node<T>* time_p = tail;
        tail = new_tail;
        time_p->pr_tail = tail;
        tail->pr_head = time_p;
    }
    size += 1;
}


template <typename T>
void Deck<T>::push_front(T item)
{
    Node<T>* new_head = new Node<T>(item);
    if (size == 0)
    {
        head = new_head;
        tail = new_head;
    }
    if(size == 1)
    {
        head = new_head;
        head->pr_tail = tail;
        tail->pr_head = head;
    }
    else
    {
        Node<T>* time_p = head;
        head = new_head;
        time_p->pr_head = head;
        head->pr_tail = time_p;
    }
    size += 1;
}

template <typename T>
void Deck<T>::pop_back()
{
    if(size != 0)
    {
        Node<T>* time_p = tail->pr_head;
        delete tail;
        tail = time_p;
        size -= 1;
        // std::cout << "pop_back" << std::endl;
    }
    else std::cout << "size is 0, nothing to pop" << std::endl;
}

template <typename T>
void Deck<T>::pop_front()
{
    if(size != 0)
    {
        Node<T>* time_p = head->pr_tail;
        delete head;
        head = time_p;
        size -= 1;
        // std::cout << "pop_front" << std::endl;
    }
    else std::cout << "size is 0, nothing to pop" << std::endl;
}

template <typename T>
T Deck<T>::get_back()
{
    return tail->value;
}

template <typename T>
T Deck<T>::get_front()
{
    return head->value;
}

template <typename T>
int Deck<T>::get_size()
{
    return size;
}