#include <iostream>
#define SIZE 10

template <class type>
class MyPriorityQueue
{
    int now_size;
    int max_size;
    type arr[SIZE];
    int first;
    int last;
    bool zahod;
public:
    
    MyPriorityQueue(int size = SIZE);
    void sort(type arr[],int size);
    void Print();
    void pop();
    void push(type item);
    int get_size();
    type peek();
};
template <class type>
void MyPriorityQueue<type>::sort(type arr[],int size)
{
    if (size > 1)
    {
        int a=1;
        bool b=true;
        while (b)
        {
            b = false;
            for(int i=0; i<size-a; i++)
            {
                if(arr[i]<arr[i+1])
                {
                    int p=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=p;
                    b = true;
                }
            }
            a++;
        }
    }
}
template <class type>
MyPriorityQueue<type>::MyPriorityQueue(int size)
{
    first = 0;
    last = -1;
    now_size = 0;
    max_size = size;
    zahod = false;
}

template <class type>
void MyPriorityQueue<type>::push(type item)
{
    if (now_size == SIZE)
    {
        std::cout << "Queue is full."<<std::endl;
        return;
    }
    //std::cout << "In " << item << std::endl;
    last = last + 1;
    
    arr[last] = item;
    //std::cout << "+ " << arr[last] <<std::endl;
    now_size++;
}

template <class type>
void MyPriorityQueue<type>::pop()
{
    if (now_size == 0)
    {
        std::cout << "Queue does not exist."<<std::endl;
    }
    
    std::cout << "remove " << arr[first] <<std::endl;
    first = first+1;
    now_size--;
    for(int i=first;i<now_size+1;i++)
    {
        std::cout<<"current queue "<< arr[i]<<std::endl;
    }
    zahod = true;
}

template <class type>
void MyPriorityQueue<type>::Print()
{
    if (zahod == false)
    {
        sort(arr,now_size);
        for(int i=first;i<now_size;i++)
        {
            std::cout<<"in "<<arr[i]<<std::endl;
        }
    }
    if (zahod == true)
    {
        sort(arr,now_size+1);
        for(int i=first;i<now_size+1;i++)
        {
            std::cout<<"in "<<arr[i]<<std::endl;
        }
    }
}
template <class type>
type MyPriorityQueue<type>::peek()
{
    if (now_size == 0)
    {
        std::cout << "Queue does not exist."<<std::endl;
        return 1;
    }
    return arr[first];
}

template <class type>
int MyPriorityQueue<type>::get_size()
{
    return now_size;
}

template <typename type>
std::ostream& operator<<(std::ostream& os, MyPriorityQueue<type> &a)
{
    os << "First element in queue: " << a.peek()<<'\n' << "Size of queue: " << a.get_size()<<'\n';
    return os;
}
int main()
{
    MyPriorityQueue<int> q(4);
    q.push(14);
    q.push(162);
    q.push(100);
    q.push(66);
    q.Print();
    std::cout << q;
    q.pop();
    q.push(150);
    q.Print();
    q.pop();
    q.pop();
    q.pop();
    
    /*MyPriorityQueue<char> q2(3);
    q2.push('B');
    q2.push('J');
    q2.push('A');
    q2.Print();
    q2.pop();*/
    
    return 0;
}


