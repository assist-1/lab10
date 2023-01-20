#include <iostream>

template<class data_type>
class MyPriorityQueue {
private:
	data_type *queue = nullptr;
	int QUEUE_SIZE;
	int front;
	int back;
	int count_elements;
public:
	MyPriorityQueue(int size);
	~MyPriorityQueue();
	void push(data_type item);
	data_type pop();
	data_type peek();
	int size();
};

int main() {

	return 0;
}
