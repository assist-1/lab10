#include<iostream>
#include<fstream>
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

template<typename type>
PriorityQueue<type>::PriorityQueue(int len1){
    items= new type[len1];
    max_len=len1;
    SIZE=0;
}

template<typename type>
PriorityQueue<type>::~PriorityQueue(){
    delete[] items;
}
template<typename type>
bool PriorityQueue<type>::is_empty(){
    return !SIZE?true:false;
}
template<typename type>
bool PriorityQueue<type>::is_full(){
    return SIZE==max_len?true:false;
}

template<typename type>
int PriorityQueue<type>::size(){return SIZE;}
template<typename type>
type PriorityQueue<type>::peek(){
    if(is_empty()){
        cout<<"PriorityQueue is empty\n";
        exit(1);
    }
    return items[0];
}
//по возрастанию
template<typename type>
void PriorityQueue<type>::push(type item){
    if(is_full()){
        cout<<"PriorityQueue is full\n";
        exit(1);
    }
    int index=-1;
    for(int i=0;i<SIZE;++i){
        if(item<items[i]){
            index=i;
            break;
        }
    }
    if (index==-1){
       items[SIZE]=item;
       SIZE++; 
    }
    else{
        for(int i=index;i<SIZE+1;++i){
            items[i+1]=items[i];
        }
        items[index]=item;
        SIZE++; 
    }
    
}
template<typename type>
type PriorityQueue<type>::pop(){
    if(is_empty()){
        cout<<"PriorityQueue is empty\n";
        exit(1);
    }
    type first=items[0];
    for(int i=0;i<SIZE-1;++i){
        items[i]=items[i+1];
    }
    SIZE--;
    return first;
   
}

int main(){
    PriorityQueue<int> a(4);

}


