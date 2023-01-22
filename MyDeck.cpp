#include <iostream>

template <class T>
class Deck {
private:
	template <typename>
	class List {
	public:
		List(T som, List* Next = NULL, List* Prev = NULL) {
			some = som;
			Next1 = Next;
			Prev1 = Prev;
		}
		T some;
		List* Next1;
		List* Prev1;
	};

	int len;
	List<T>* head;
	List<T>* tail;

	friend std::ostream& operator<<(std::ostream& out,const Deck<T>& M) {
		auto M1 = M.head;
		while (M1 != NULL) {
			out << M1->some << " ";
			M1 = M1->Next1;
		}
		return out;
	}

public:
	Deck() {
		len = 0;
		head = NULL;
		tail = NULL;
	}

	~Deck() {
		while (len>0) {
			pop_front();
		}
	}

	int get_size();
	void push_back(T some);
	void push_front(T some);
	void pop_back();
	void pop_front();
};

template <typename T>
int Deck<T>::get_size() {
	return len;
}

template <typename T>
void Deck<T>::push_back(T some) {
	if (head == NULL) {
		head = new List<T>(some);
		tail = head;
	}
	else {
		tail->Next1 = new List<T>(some, NULL, tail);
		tail = tail->Next1;
	}
	len++;
}

template <typename T>
void Deck<T>::push_front(T some) {
	head = new List<T>(some, head, NULL);
	len++;
}

template <typename T>
void Deck<T>::pop_back() {
	if (len == 0) return;
	if (len == 1) {
		tail = NULL;
		head = NULL;
		len--;
		return;
	}
	tail = tail->Prev1;
	tail ->Next1 = NULL;
	len--;
}

template <typename T>
void Deck<T>::pop_front() {
	if (len == 0) return;
	if (len == 1) {
		head = NULL;
		tail = NULL;
		len--;
		return;
	}
	head = head->Next1;
	head->Prev1 = NULL;
	len--;
}

int main() {
	Deck<int> s;
	s.push_back(90);
	s.push_front(10);
	s.push_back(80);
	std::cout <<"[ " << s << "]" << std::endl;
	std::cout << "Number of elements: "<< s.get_size() << std::endl;
	s.pop_front();
	s.pop_back();
	std::cout << "[ " << s << "]" << std::endl;
	std::cout << "Number of elements: " << s.get_size() << std::endl;
	s.pop_back();
	s.pop_back(); // не выдаст ошибку, но и ничего не удалит, так как нет элементов

	Deck<char> a;
	a.push_back('a');
	a.push_back('b');
	a.push_front('s');
	a.push_front('p');
	std::cout << "[ " << a << "]" << std::endl;
	std::cout << "Number of elements: " << a.get_size() << std::endl;
	a.pop_back();
	a.pop_front();
	std::cout << "[ " << a << "]" << std::endl;
	std::cout << "Number of elements: " << a.get_size() << std::endl;
	return 0;
}