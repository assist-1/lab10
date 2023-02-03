#include <iostream>
using namespace std;
#define SIZE 100
int sizee;
template <class N>
class MyDeck {
	N items[SIZE];
	int size = 0;
	friend ostream& operator <<<N>(ostream& os, MyDeck& rhs);
public:
	void push_front(N item);
	void push_back(N item);
	N pop_front();
	N pop_back();
	int get_size();
	N vivod(int i);
};



template <typename N>
int MyDeck<N>::get_size() {

	cout << "Size MyDeck = " << size << endl
		<< "|______________|" << endl;
	return size;
}

template <typename N>
N MyDeck<N>::vivod(int i) {
	return items[i];
}

template <typename N>
void MyDeck<N>::push_front(N item) {
	N items2[SIZE];
	for (int i = 1; i < size + 1; i++) {
		items2[i] = items[i - 1];
	}
	items2[0] = item;
	size++;
	for (int i = 0; i < size; i++) {
		items[i] = items2[i];
	}
	sizee = size;
}


template <typename N>
void MyDeck<N>::push_back(N item) {
	items[size] = item;
	size++;
	sizee = size;
}


template <typename N>
N MyDeck<N>::pop_back() {
	if (size == 0) {
		cout << "MyDeck is empty" << endl;
		return 0;
	}
	size--;
	sizee--;
	return items[size];
	cout << sizee;
}


template <typename N>
N MyDeck<N>::pop_front() {
	if (size == 0) {
		cout << "MyDeck is empty" << endl;
		return 0;
	}
	N items2[SIZE];
	for (int i = 1; i < size; i++) {
		items2[i - 1] = items[i];
	}
	size--;
	sizee--;
	for (int i = 0; i < size; i++) {
		items[i] = items2[i];
	}
	return items[size];

}



template< typename N>
ostream& operator<<(std::ostream& os, MyDeck<N>& rhs)
{
	for (int i = 0; i < sizee; i++) {
		if (sizee == 0) {
			return os;
		}
		os << i + 1 << ". [" << rhs.vivod(i) << "]" << endl;
	}
	return os;
}




int main() {
	MyDeck<char> B;
	B.push_back('F');
	B.push_back('M');
	B.push_front('I');
	B.push_back('F');
	B.push_back('M');
	B.push_front('9');
	B.push_back('1');
	B.push_back('M');
	B.push_front('I');
	B.pop_front();
	B.pop_back();
	B.get_size();
	cout << B;
};