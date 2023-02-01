#include <iostream>
using std::cout;
using std::endl;
template <typename T>
class Deque
{
	struct Node {
	Node(T elem) // c-tor Node
	{
		exp = elem;
	}
    Node* pointer_h = nullptr;
    Node* pointer_t = nullptr;
    T exp;

	};

    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

public:
    ~Deck() while(size != 0) pop_front();
    void push_back(T elem)
	{
		Node* back_elem = new Node(elem);
		if (head == 0)
		{
			tail = back_elem;
			head = back_elem;
		}
		else
		{
			back_elem->pointer_h =  tail;
			tail->pointer_t = back_elem;
			tail = back_elem;
		}
	}

    void push_front(T elem)
	{
		Node* fr_elem = new Node(elem);
		if (head == 0)
		{
			tail = fr_elem;
			head = fr_elem;
		}
		else
		{
			fr_elem->pointer_t =  head;
			head->pointer_h = fr_elem;
			head = fr_elem;
		}
	}

	void pop_back()
	{
		if(size != 0)
    {
        tail = tail->pointer_h;
		tail->pointer_t = nullptr;
    }
		else cout << "Deck is clear, his size - 0" << endl;
	}

	void pop_front()
	{
		if (size != 0)
    {
		head = head->pointer_t;
		head->pointer_h = nullptr;
    }
    else std::cout << "Deck is clear, his size - 0" << std::endl;
	}
    friend std::ostream& operator<< (std::ostream& os, Deck<T> & deck)
    {
        int lenght = deck.get_size();
        Node* pointer_t = deck.tail;
        for (int i = 0; i < lenght; i++)
        {
            os << pointer_t->exp << " ";
            pointer_t = pointer_t->pointer_h;
        }
        return os;
    }
	int get_size(){ return size;}
};

