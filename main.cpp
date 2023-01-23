#include <iostream>

template <typename Type>
class Dek;

template <typename Type>
std::ostream& operator<< (std::ostream& stream,Dek<Type>& dek){
   dek.ptr1 = dek.head;
   for(int i = 0; i < dek.count; i ++){
       stream << "element: " << dek.ptr1->value << " - number of element: " << i << std::endl;
       dek.ptr1 = dek.ptr1->next;
   }
   return stream;
}

template <typename Type>
class Dek{
private:
    friend std::ostream& operator<< <Type>(std::ostream& stream, Dek<Type>& dek);
    struct Num{
        Type value;
        Num *pred, *next;
        Num(Type a){
            value = a;
            pred = next = nullptr;
        }
    };
    Num *head, *tail, *ptr1;
    int count;
public:
    Dek(){
        head = tail = ptr1 = nullptr;
        count = 0;
    }
    ~Dek(){
        for(int i = 0; i < count; i++){
            if(head->next != nullptr) {
                Num *ptr = head->next;
                delete head;
                head = ptr;
            } else {
                delete head;
            }
        }
    }
    void push_back(Type item) {
        Num *ptr = new Num(item);
        if (tail != nullptr) {
            tail->next = ptr;
            ptr->pred = tail;
            tail = ptr;
        } else {
            head = tail = ptr;
        }
        count++;

    }
    void push_front(Type item){
        Num *ptr = new Num(item);
        if(head != nullptr){
            head->pred = ptr;
            ptr->next = head;
            head = ptr;
        } else {
            head = tail = ptr;
        }
        count++;
    }
    void pop_back(){
        if(count == 0){
            std::cerr << "ERROR POP_BACK"<< std::endl;
            return;
        } else if (count != 1){
            tail = tail->pred;
            delete [](tail->next);
            tail->next = nullptr;
        } else {
            delete tail;
            tail = head = nullptr;
        }
        count--;
    }
    void pop_front(){
        if(count == 0){
            std::cerr << "ERROR POP_BACK" << std::endl;
            return;
        } else if (count != 1){
            head = head->next;
            delete [](head->pred);
            head->pred = nullptr;
        } else {
            delete head;
            tail = head = nullptr;
        }
        count--;
    }
    void get_size(){
        std::cout <<"Size: " << count << std::endl;
    }
};



int main() {
    Dek <char> a;
    a.push_back('a');
    a.push_front('e');
    a.push_back('d');
    a.pop_back();
    a.push_front('t');
    a.pop_back();
    a.pop_front();
    a.get_size();

    Dek <int> g;
    g.push_front(3);
    g.push_back(4);
    g.pop_back();
    g.push_front(2);
    g.get_size();
    std::cout << std::endl << g << std::endl << a;

    Dek <double> d;
    d.push_front(3232.1);
    d.push_back(4444.234);
    d.pop_front();
    d.pop_front();
    d.push_front(2222.22);
    std::cout << d;
    return 0;
}