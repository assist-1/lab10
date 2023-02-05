#include <iostream>

template <typename wuw>
class priority_queue{
    private:
        int size;
        const int max_size = 50;
        wuw data[50];
        int order[50];

    public:
        priority_queue();
        ~priority_queue();
        int get_size();
        wuw pop();
        wuw fast_pop();
        void push(wuw, int);
        int get_max_size();
};

template <typename wuw>
priority_queue<wuw>::priority_queue():size(0){}

template <typename wuw>
priority_queue<wuw>::~priority_queue(){}

template <typename wuw>
int priority_queue<wuw>::get_size(){return size;}

template <typename wuw>
int priority_queue<wuw>::get_max_size(){return max_size;}

template <typename wuw>
void priority_queue<wuw>::push(wuw a, int b){
    ++size;
    if (size > max_size){
        std::cout << "error, u pushed toooo much";
    }
    else{
        int place = 0;
        for (int i = 0; i < size - 1; ++i){
            if (order[i] < b){
                place = i;
                break;
            }
            else if (i == size - 2){
                place = size - 1;
                break;
            }
        }
        for (int i = size - 2; i >= place; --i){
            data[i + 1] = data[i];
            order[i + 1] = order[i];
        }
        order[place] = b;
        data[place] = a;
    }
}


template <typename wuw>
std::ostream& operator << (std::ostream &os, priority_queue<wuw> &a)
{
    int k = a.get_size();
    for (int i = 0; i < k; ++i){
        os << a.pop() << ' ';
    }
    return os;
}

template <typename wuw>
wuw priority_queue<wuw>::pop(){
    if (!size){
        std::cout << "queue is empty" << std::endl;
        return 0;
    }
    --size;
    wuw k = data[size];
    data[size] = 0;
    order[size] = 0;
    return k;
}


int main(){
    priority_queue<int> a;
    for (int i = 0; i < 10; ++i){
        a.push(i, -i);
    }
    for (int i = 0; i < 10; ++i){
        a.push(2 * i, i);
    }
    std::cout << a;
    return 0;
}