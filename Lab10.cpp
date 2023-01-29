#include <iostream>

#define SIZE 10

using std::cout;
using std::endl;

template<class T>
class MyPriorityQueue
{
private:
    T queue[SIZE];
public:
    int s = 0;
    void push(T item);
    T pop();
    T peek();
    int size() {
        return s;
    }
    T operator[](int i) {   return queue[i];}
};

template<typename T>
std::ostream& operator<<(std::ostream &out, MyPriorityQueue<T> q)
{
    if (q.s==0) out << "EMPTY\n";
    else if (q.s != 0) {
        out << "[ ";
        for (int i = 0; i < q.s; ++i) out << q[i] << " ";
        out << "]\n";
    }
    return out;
}

template<typename T>
void MyPriorityQueue<T>::push(T item) {
    if (s==SIZE) cout << "FULL" << endl;
    else {
        cout << "You added " << item << " to the QUEUE\n";
        queue[s] = item;
        ++s;
    }
}

template<typename T>
T MyPriorityQueue<T>::pop() {
    if (s==0) {
        cout << "EMPTY\n";
        return 0;
    }
    else {
        T gitem = queue[0];
        for (int i = 0; i < SIZE-1; ++i) {
            queue[i] = queue[i+1];
        }
        --s;
        cout << "You removed " << gitem << " from the QUEUE\n";
        return gitem;
    }
}

template<typename T>
T MyPriorityQueue<T>::peek() {
    if (s==0) {
        cout << "EMPTY\n";
        return 0;
    }
    else {
        return queue[0];
    }
}

int main() {
    MyPriorityQueue<char> q;
    q.pop();
    cout << q;
    q.push('Q');
    cout << "SIZE = " << q.size() << endl;
    cout << q;
    q.pop();
    cout << "SIZE = " << q.size() << endl;
    q.push('T');
    cout <<"Peek item: " << q.peek() << endl;
    q.push('H');
    q.push('U');
    q.push('N');
    q.push('D');
    q.push('E');
    q.push('R');
    cout << "SIZE = " << q.size() << endl;
    q.push('2');
    q.push('9');
    q.push('!');
    q.push('1');
    cout << q;
    return 0;
}