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

// ***description of class methods***

template<typename data_type>
MyPriorityQueue<data_type>::MyPriorityQueue(int size) {
	if(size <= 0) {
		std::cerr << "ERROR: Queue size must be a natural number!" << std::endl;
		exit(1);
	}
	queue = new data_type[size];
	QUEUE_SIZE = size, front = 0, back = 0, count_elements = 0;
}

template<typename data_type>
MyPriorityQueue<data_type>::~MyPriorityQueue() {
	delete [] queue;
	queue = nullptr;
}

template<typename data_type>
void MyPriorityQueue<data_type>::push(data_type item) {
	if(count_elements == QUEUE_SIZE) {
		std::cerr << "ERROR: The number of queue items has reached the maximum!" << std::endl;
		exit(1);
	}
	queue[back++ % QUEUE_SIZE] = item;
	count_elements++;
}

template<typename data_type>
data_type MyPriorityQueue<data_type>::pop() {
	if(count_elements == 0) {
		std::cerr << "ERROR: The number of queue items is zero!" << std::endl;
		exit(1);
	}
	count_elements--;
	return queue[front++ % QUEUE_SIZE];
}

