#include <iostream>
#include "MyDeck.h"

using std::cin;
using std::cout;

class Point {
 public:
    int x;
    int y;
    void print();
};

std::ostream& operator<<(std::ostream& out, Point p) {
    out << '(' << p.x << "; " << p.y << ')';
    return out;
}

int main(int argc, char **argv) {
    MyDeck<int> int_deque;

    MyDeck<char> char_deque;

    MyDeck<Point> point_deque;
    
    return 0;
}
