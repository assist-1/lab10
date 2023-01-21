#include<iostream>
using std::cout;
template<class type>
class PriorityQueue{
    private:
    type *items;
    int max_len;
    int SIZE;
    public:
    PriorityQueue(int);
    ~PriorityQueue();
    int size();
    void push(type);
    type pop();
    bool is_empty();
    bool is_full();
    type peek();
};
