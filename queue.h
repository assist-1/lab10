template <typename T>
class Queue
{
public:
	void push(T);
	void pop();
	T peek();
	int get_size();
	~Queue();
	friend std::ostream& operator <<(std::ostream& os, Queue<T>& queue)
	{
		Node<T>* pointer = queue.first;
		for(int i = 0; i < queue.get_size();i++)
		{
			os << pointer->value << " ";
			pointer = pointer->pr;
		}
		return os;
	}
private:
	int size = 0;
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
};

template <typename T>
void Queue<T>::push(T item)
{
	if (size == 0)
	{
		first = new Node<T>;
		first->value = item;
		last = first;
	}
	else
	{
		Node<T>* time_last = new Node<T>;
		last->pr = time_last;
		last = time_last;
		last->value = item;
	}
	size += 1;
}

template <typename T>
void Queue<T>::pop()
{
	if (size == 0)
	{
		std::cout << "queue is empty" << std::endl;
		exit(1);
	}
	else
	{
		Node<T>* for_delete = first;
		first = first->pr;
		delete for_delete;
		size-=1;
	}
}

template <typename T>
T Queue<T>::peek()
{
	if(size == 0)
	{
		std::cout << "queue is empty" << std::endl;
		exit(1);
	}
	return first->value;
}

template <typename T>
int Queue<T>::get_size()
{
	return size;
}

template <typename T>
Queue<T>::~Queue()
{
	while (size != 0)
	{
		pop();
	}
}