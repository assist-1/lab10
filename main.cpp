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

    cout << "Size of the deck is " << int_deque.size() << '\n' << '\n';
    //cout << int_deque.front() << '\n';
    
    int_deque.push_front(15); //15
    cout << "Size of the deck is " << int_deque.size() << '\n';
    cout << "Front value of the deck is " << int_deque.front() << '\n';
    cout << "Back value of the deck is " << int_deque.back() << '\n' << '\n';

    int_deque.push_back(14); //15 14
    cout << "Size of the deck is " << int_deque.size() << '\n';
    cout << "Front value of the deck is " << int_deque.front() << '\n';
    cout << "Back value of the deck is " << int_deque.back() << '\n' << '\n';

    int_deque.push_back(13); //15 14 13
    cout << "Size of the deck is " << int_deque.size() << '\n';
    cout << "Front value of the deck is " << int_deque.front() << '\n';
    cout << "Back value of the deck is " << int_deque.back() << '\n' << '\n';

    int_deque.pop_back();//15 14
    cout << "Size of the deck is " << int_deque.size() << '\n';
    cout << "Front value of the deck is " << int_deque.front() << '\n';
    cout << "Back value of the deck is " << int_deque.back() << '\n' << '\n';
    



    //MyDeck<char> char_deque;

    //MyDeck<Point> point_deque;
    
    return 0;
}
