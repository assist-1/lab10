#include <iostream>


template <class ValueType>
class Element{
private:
    ValueType value;
    Element* next;
public:
    Element(): next(nullptr){};
    explicit Element(ValueType v): value(v), next(nullptr){};
    explicit Element(ValueType v, ValueType* n): value(v), next(n){};
    explicit Element(ValueType v, ValueType* n, ValueType* p): value(v), next(n){};
    explicit Element(Element<ValueType>* e): value(e->get_value()), next(e->get_next()){};

    void set_next(Element<ValueType>* n){
        this->next=n;
    }

    Element* get_next(){
        return next;
    }

    ValueType get_value(){
        return value;
    }
};


template <class ListType>
class List{
protected:
    Element<ListType>* first;
    int len;
public:
    List(){
        Element<ListType> empty;
        first = &empty;
        len = 0;
    }

    List(Element<ListType>* e){
        first = e;
        len = 1;
    }

    ~List(){
        for(int i = 0; i < len; ++i) {
            Element<ListType> *a = this->first->get_next();
            delete this->first;
            this->first = a;
        }
    }

    int get_size(){
        return len;
    }

    void print(){
        Element<ListType> a = *first;
        for(int i = 0; i < len; i++){
            std::cout << a.get_value() << ' ';
            if(i < len - 1) a = *a.get_next();
        }
        std::cout << "\n";
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
