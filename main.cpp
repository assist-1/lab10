#include <iostream>
#include "classes.h"

int main() {
    priority_queue<int, int> A;
    A.push(87);
    A.push(20);
    A.push(10);
    A.push(70);
    A.push(1);
    std::cout << A << "\n\n";
    std::cout << "       " << A.pop() << "\n\n";
    A.pop();
    A.pop();
    std::cout << A << "\n\n";
    std::cout << "size: " << A.size() << "        last element: " << A.peek();
}