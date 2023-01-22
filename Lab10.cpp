#include <iostream>

using std::cout;
using std::endl;

template<class T>
class MyPriorityQueue
{
private:
    T queue[10];
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
    else if (q.s == 1) out << "[ " << q[0] << " ]\n";
    else if (q.s == 2) out << "[ " << q[0] << ", " << q[1] << " ]\n";
    else if (q.s == 3) out << "[ " << q[0] << ", " << q[1] << ", " << q[2] << " ]\n";
    else if (q.s == 4) out << "[ " << q[0] << ", " << q[1] << ", " << q[2] << ", " << q[3] << " ]\n";
    else if (q.s == 5) out << "[ " << q[0] << ", " << q[1] << ", " << q[2] << ", " << q[3] << ", " << q[4] << " ]\n";
    else if (q.s == 6) out << "[ " << q[0] << ", " << q[1] << ", " << q[2] << ", " << q[3] << ", " << q[4] << ", " << q[5] << " ]\n";
    else if (q.s == 7) out << "[ " << q[0] << ", " << q[1] << ", " << q[2] << ", " << q[3] << ", " << q[4] << ", " << q[5] << ", " << q[6] << " ]\n";
    else if (q.s == 8) out << "[ " << q[0] << ", " << q[1] << ", " << q[2] << ", " << q[3] << ", " << q[4] << ", " << q[5] << ", " << q[6] << ", " << q[7] << " ]\n";
    else if (q.s == 9) out << "[ " << q[0] << ", " << q[1] << ", " << q[2] << ", " << q[3] << ", " << q[4] << ", " << q[5] << ", " << q[6] << ", " << q[7] << ", " << q[8] << " ]\n";
    else if (q.s == 10) out << "[ " << q[0] << ", " << q[1] << ", " << q[2] << ", " << q[3] << ", " << q[4] << ", " << q[5] << ", " << q[6] << ", " << q[7] << ", " << q[8] << ", " << q[9] << " ]\n";
    return out;
}

template<typename T>
void MyPriorityQueue<T>::push(T item) {
    if (s==10) cout << "FULL" << endl;
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
        for (int i = 0; i < 9; ++i) {
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