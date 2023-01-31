#include <iostream>
#include <cstdlib>
using namespace std;
 

template <typename type>
class queue {
    private:
        type *arr;
        int max;
        int first;
        int last; 
        int current_size;
    public:
        queue(int size = 10);
        void out();
        void in(type value);
        type peek();
        int size();
        bool is_empty();
        bool is_full();

    private:
    friend std::ostream& operator<<(std::ostream& os, queue<type>& q){
      for (int i = 0; i < q.max; i++){
          os << q.peek() << endl;
          q.out();
      }
      return os;
    }
};
 
template <class type>
queue<type>::queue(int size){
    arr = new type[size];
    max = size;
    first = 0;
    last = -1;
    current_size = 0;
}

template <class type>
bool queue<type>::is_empty(){
    return (size() == 0);
}

template <class type>
bool queue<type>::is_full(){
    return (size() == max);
}

template <class type>
int queue<type>::size(){
    return current_size;
}

template <class type>
void queue<type>::in(type value){
    if (is_full()){
        cout << "Ошибка" << endl;
        exit(EXIT_FAILURE);
    }
    last = (last + 1) % max;
    arr[last] = value;
    current_size++;
}

template <class type>
void queue<type>::out(){
    if (is_empty()){
        cout << "Ошибка" << endl;
        exit(EXIT_FAILURE);
    }
    first = (first + 1) % max;
    current_size--;
}

template <class type>
type queue<type>::peek(){
    if (is_empty()){
        cout << "Ошибка" << endl;
        exit(EXIT_FAILURE);
    }
    return arr[first];
}
 
int main(){
    int size;
    cout << "Введите размер куеуе: ";
    cin >> size;
    queue<int> queue(size);
    if (queue.is_empty()){
        cout << "Очередь пустая, заполяем очередь, она выглядит так: " << endl;
    }
    for (int i = 1; i <= size; i++){
        cout << i << endl;
        queue.in(i);
    }
    if (queue.is_full()){
        cout << "Очередь заполнена" << endl;
    }
    cout << "Добавляем и убираем элемент " << endl;
    queue.out();
    queue.in(size+1);
    cout << "Теперь очередь выглядит вот так: " << endl;
    cout << queue << endl;
    return 0;
}
