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

template <typename T>
void print(MyDeck<T> & my_deque){
    cout << "Size of the deck is " << my_deque.size() << '\n';
    cout << "Front value of the deck is " << my_deque.front() << '\n';
    cout << "Back value of the deck is " << my_deque.back() << '\n';
}

int main(int argc, char **argv) {
    MyDeck<int> int_deque;
    cout << "INT DECK" << '\n';
    cout << "Size of the deck is " << int_deque.size() << '\n';
    //cout << int_deque.front() << '\n';
    
    int_deque.push_front(15); //15
    print<int>(int_deque);
    cout << int_deque << '\n' << '\n';

    
    int_deque.push_back(14); //15 14
    print<int>(int_deque);
    cout << int_deque << '\n' << '\n';

    int_deque.push_back(13); //15 14 13
    print<int>(int_deque);
    cout << int_deque << '\n' << '\n';

    int_deque.pop_back();//15 14
    print<int>(int_deque);
    cout << int_deque << '\n' << '\n';

    int_deque.pop_front();//14
    print<int>(int_deque);
    cout << int_deque << '\n' << '\n';
    
    //MyDeck<char> char_deque;
    cout << "CHAR DECK" << '\n';
    MyDeck<char> char_deque;
    cout << char_deque << '\n' << '\n';

    cout << "Size of the deck is " << char_deque.size() << '\n' << '\n';
    
    char_deque.push_back('1'); //0 1
    print<char>(char_deque);
    cout << char_deque << '\n' << '\n';

    char_deque.push_front('0'); //'0'
    print<char>(char_deque);
    cout << char_deque << '\n' << '\n';
    

    char_deque.push_back('2'); //0 1 2 
    print<char>(char_deque);
    cout << char_deque << '\n' << '\n';

    char_deque.pop_back();//0 1
    print<char>(char_deque);
    cout << char_deque << '\n' << '\n';
    
    char_deque.pop_front();//1
    print<char>(char_deque);
    cout << char_deque << '\n' << '\n';
    
    return 0;
}
