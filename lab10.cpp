#include <iostream>

template <class T>
class mydeque
{
    private:
    struct Node
    {
        T data;
        Node* next;
        Node* prev;
        Node(T data,Node* prev = nullptr, Node* curr = nullptr):data(data),next(curr),prev(prev)
                {
                    if(prev != nullptr) prev->next = this;
                    if(curr != nullptr) curr->prev = this;
                }
    };
    Node* head;
    Node* tail;
    unsigned int nodes_count;
    bool remove_node(Node* node)
    {
        if (node == nullptr) return false;
        if (node->prev != nullptr)
        {
            node->prev->next = node->next;
        }
        else head = node->next;
        if (node->next !=nullptr)
        {
            node->next->prev = node->prev;
        }
        else tail = node->prev;
        delete node;
        nodes_count--;
        return true;
    }
    Node* get_elem(unsigned index)
    {
        if (index<0 || index>= nodes_count)
        {
            return nullptr;
        }
        Node* elem;
        if (index <= nodes_count)
        {
            elem = head;
            for (int i=0;i<index;i++)
            {
                elem = elem->next;
            }
        }
        else
        {
            elem = tail;
            for(int i = nodes_count-1;i>index;i-- )
            {
                elem = elem->prev;
            }
        }
        return elem;
    }
    friend std::ostream& operator<<(std::ostream& os, const mydeque<T>& obj)
    {
        for (Node* i = obj.head; i != NULL; i = i->next)
            os << i->data << " ";
        return os;
    }
    public:
    mydeque():nodes_count(0),head(nullptr),tail(nullptr){}
    unsigned size()
    {
        return nodes_count;
    }
    void insert(unsigned index, T new_elem)
    {
        if(index<0 || index> nodes_count) std::cerr<<"Index is out of range!\n";
        else
        {
            if (nodes_count ==0)
            {
                head = new Node(new_elem);
                tail = head;
            }
            else
            {
                if (index ==nodes_count) tail = new Node(new_elem,tail,nullptr);
                else if (index ==0) head = new Node(new_elem,nullptr,head);
                else
                {
                    Node* curr = get_elem(index);
                    new Node(new_elem,curr->prev,curr);
                }

            }
        }
        nodes_count++;
    }
    void push_front(T new_elem)
    {
        insert(0,new_elem);
    }
    void push_back(T new_elment)
    {
        insert(nodes_count,new_elment);
    }
    bool remove_at(unsigned pos)
	{
		return remove_node(get_elem(pos));
	}
    bool pop_back()
	{
		return remove_at(nodes_count - 1);
	}
    bool pop_front()
	{
		return remove_at(0);
	}
    ~mydeque(){}
};

main()
{
    mydeque<int> a;
    a.push_back(2);
    std::cout << a <<std::endl;
    a.push_front(8);
    std::cout << a <<std::endl;
    a.push_front(25);
    std::cout << a <<std::endl;
    a.pop_back();
    std::cout << a <<std::endl;
    std::cout << a.size() <<std::endl;
    a.pop_front();
    std::cout << a <<std::endl;
    a.pop_front();
}