#include <iostream>

template<class T>
class MyPriorityQueue{
    int sz;
    int length;
    T* elems;
public:
    MyPriorityQueue(int sz) : sz(sz), length(0) {
        elems = new T[sz];
    }
    void push(T);
    void pop();
    T peek();
    int size();
    std::ostream& pr(std::ostream& out) {
        for (int i = 0; i < length; ++i) {
            out << elems[i] << ' ';
        }
        return out;
    }
};

template<typename T>
void MyPriorityQueue<T>::push(T el) {
    if (length == 0) {
        elems[0] = el;
        length++;
        return;
    }
    if (length == sz) {
        std::cout << "Massive is full\n";
        return;
    }
    for (int i = 0; i < length; ++i) {
        if (elems[i] <= el) {
            for (int j = length-1; j >= i; --j) {
                elems[j+1] = elems[j];
            }
            elems[i] = el;
            length++;
            return;
        }
        else if (i == length - 1) {
            elems[length++] = el;
            return;
        }
    }
    return;
}


template<typename T>
int MyPriorityQueue<T>::size() {
    return sz;
}

template<typename T>
void MyPriorityQueue<T>::pop(){
    if(sz == 0){
        std::cout<<"Queue is empty\n";
        return;
    }
    T first=elems[0];
    for(int i = 0;i < sz - 1; ++i){
        elems[i]=elems[i+1];
    }
    sz--;
    return int(first) ;
}


template<typename T>
std::ostream& operator<<(std::ostream& out, MyPriorityQueue<T>& queue) {
    return queue.pr(out);
}

int main() {
    MyPriorityQueue<int> q(5);
    q.push(1);
    q.push(3);
    q.push(2);
    q.push(4);
    q.push(4);
    q.pop();

    std::cout << q << std::endl;
}
