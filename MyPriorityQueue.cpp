#include"MyPriorityQueue.h"
template<typename type>
PriorityQueue<type>::PriorityQueue(int len1){
    items= new type[len1];
    max_len=len1;
    SIZE=0;
    counter=-1;
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
void PriorityQueue<type>::push(type item){
     if(is_full()){
        cout<<"Queue is full\n";
        exit(1);
    }
    if(is_empty()){
    items[SIZE]=item;
    SIZE++;
    }
    else{
        index=-1;
        for(int i=0;i<SIZE;++i){
            if(item<items[i]){
                index=i;
            }
        }
        if(index==-1){
            for(int i=SIZE;i>0;--i){
                items[i]=items[i-1];
            }
            items[0]=item;
            SIZE++;
        }
        else{
            for(int i=SIZE;i>index;--i){
                items[i]=items[i-1];
            }
            items[index+1]=item;
            SIZE++;
        }
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
template<typename type>
type PriorityQueue<type>::peek(){
    if(is_empty()){
        cout<<"PriorityQueue is empty\n";
        exit(1);
    }
    counter++;
    return items[counter];

}
template<typename type>
std::ostream& operator<<(std::ostream& stream, PriorityQueue<type> &p) {
    int n=p.size();
    for (int i=0;i<n;++i){
    stream<<p.peek()<<'\n';
    }
    p.counter=-1;
    return stream;
}
int main(){
PriorityQueue<int> a(9);
a.push(3);
a.push(14);
a.push(17);
a.push(55);
a.push(26);
a.push(14);
a.push(2);
a.push(1);
a.push(108);
cout<<a;

}



