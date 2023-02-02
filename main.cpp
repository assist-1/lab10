#include <iostream>
#include "node.h"
#include "queue.h"


int main()
{
	Queue<float> q;
	q.push(1.5);
	q.push(2.3);
	q.push(34.7);
	std::cout << q << std::endl;
	std::cout << "size " << q.get_size() << std::endl; 
	std::cout << q.peek() << std::endl;
	q.pop();
	std::cout << q.peek() << std::endl;
	q.pop();
	q.push(3);
	std::cout << q.peek() << std::endl;
	std::cout << "size " << q.get_size() << std::endl; 
	
	return 0;
}