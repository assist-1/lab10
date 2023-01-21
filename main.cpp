#include <iostream>

template <class T>
class Item {
public:
	T element;
	Item<T>* next; //pointer of next element
	Item<T>* prev; //pointer of previous element
	Item<T> (T elem) : element(elem), next(nullptr), prev(nullptr) {}
    ~Item<T> () {};
};

template <class T>
class MyDeck {
public:
	int size_of_deck;
	Item<T>* first; //beginning of MyDeck
	Item<T>* last; //ending of MyDeck
	MyDeck();
	void push_back(T it);
	void pop_back();
	void push_front(T it);
	void pop_front();
	int size();
	~MyDeck();
};

template <class T>
MyDeck<T>::MyDeck() {
	size_of_deck = 0;
	first = nullptr;
	last = nullptr;
}

template <class T>
MyDeck<T>::~MyDeck() {
	while (last != nullptr) {
		pop_back();
	}
	--size_of_deck;
}

template <class T>
void MyDeck<T>::push_back(T it) {
	Item<T>* p = new Item<T>(it);
	p->prev = last;
	if (last != nullptr) { //if MyDeck is not empty
		last->next = p;
		last = p;
	}
	else { //if MyDeck is empty
		first = p;
		last = p;
	}
	++size_of_deck;
}

template <class T>
void MyDeck<T>::pop_back() {
	if (last == nullptr) { //if MyDeck is empty (there is nothing to pop_back)
	    std::cout << "MyDeck is empty: there is nothing to pop_back" << std::endl;
		return;
	}
	else {
		Item<T>* p = last->prev;
		if (p != nullptr) { //there are two elements in MyDeck at least
			p->next = nullptr;
			delete last;
			last = p;
		}
		else { //there is only one element in MyDeck
			first = nullptr;
			delete last;
			last = nullptr;
		}
	}
	--size_of_deck;
}

template <class T>
void MyDeck<T>::push_front(T it) {
	Item<T>* p = new Item<T>(it);
	p->next = first;
	if (first != nullptr) {
		first->prev = p;
		first = p;
	}
	else { //if MyDeck is empty
		last = p;
		first = p;
	}
	++size_of_deck;
}

template <class T>
void MyDeck<T>::pop_front() {
	if (first == nullptr) { //if MyDeck is empty (there is nothing to pop_front)
	    std::cout << "MyDeck is empty: there is nothing to pop_front" << std::endl;
		return;
	}
	else {
		Item<T>* p = first->next;
		if (p != nullptr) { //there are two elements in MyDeck at least
			p->prev = nullptr;
			delete first;
			first = p;
		}
		else { //there is only one element in MyDeck
			last = nullptr;
			delete first;
			first = nullptr;
		}
	}
	--size_of_deck;
}

template <class T>
int MyDeck<T>::size() {
	return size_of_deck;
}

template <class T>
std::ostream& operator<<(std::ostream& out, MyDeck<T>& list) {
	Item<T>* el = list.first;
	for (int i = 0; i < list.size_of_deck; ++i) {
		out << el->element << " ";
		el = el->next;
	}
	out << '\n';
	return out;
}

int main() {
    std::cout << "First example: " << std::endl;
    MyDeck<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_front(4);
    lst.push_front(5);
    std::cout << lst;
    lst.pop_back();
    lst.pop_front();
    std::cout << lst;
    std::cout << lst.size() << std::endl;
    std::cout << "Second example: " << std::endl;
    MyDeck<double> prime;
    prime.push_back(1.57);
    std::cout << prime;
    prime.pop_back();
    std::cout << prime.size() << std::endl;
    prime.pop_back();
    prime.push_front(2.43);
    std::cout << prime;
    prime.pop_front();
    std::cout << prime.size() << std::endl;
    prime.pop_front();
    std::cout << "Third example: " << std::endl;
    MyDeck<char> literal;
    literal.push_front('a');
    literal.push_front('b');
    literal.push_front('c');
    std::cout << literal;
    literal.pop_back();
    literal.pop_back();
    std::cout << literal;
    std::cout << literal.size() << std::endl;
    return 0;
}