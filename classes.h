#ifndef LAB_10_CLASSES_H
#define LAB_10_CLASSES_H

#include <iostream>

template <typename type_for_element>
class Element {
private:
    type_for_element item;
    Element* next;
    Element* previous;
public:
    Element() : next(nullptr), previous(nullptr){};
    explicit Element(const type_for_element& new_one) : next(nullptr), previous(nullptr){ this->item = new_one; }
    explicit Element(const Element* new_one){
        this->item = new_one->get_item();
        this->next = new_one->get_next();
        this->previous = new_one->get_previous();
    }
    ~Element() = default;

    type_for_element get_item(){ return this->item; }
    Element* get_next(){ return this->next; }
    Element* get_previous(){ return this->previous; }

    void change_next(Element* new_one){ this->next = new_one; }
    void change_previous(Element* new_one){ this->previous = new_one; }
    void change_item(type_for_element new_one){ this->item = new_one; }
};

template <typename type_for_list, typename limit>
class list{
public:
    limit n;
    Element<type_for_list>* start_list = new Element<type_for_list>;
    Element<type_for_list>* end_list = new Element<type_for_list>;
public:
    list(){ this->n = 0; };
    ~list(){
        for (limit i = this->n; i > 1; --i){
            end_list = end_list->get_previous();
            delete end_list->get_next();
        }
        delete start_list;
    }

    virtual void push(type_for_list item) = 0;

    limit size(){ return this->n; }
};

template <typename type_for_deck, typename limit>
class priority_queue : public list<type_for_deck, limit>{
public:

    priority_queue() = default;

    void push(type_for_deck item) override {
        Element<type_for_deck> *new_one = new Element<type_for_deck>(item);
        switch (this->n) {
            case 0 : {
                this->start_list->change_item(item);
                this->end_list->change_previous(this->start_list);
                break;
            }
            case 1 : {
                if (item <= this->start_list->get_item())
                    this->end_list->change_item(item);
                else {
                    this->end_list->change_item(this->start_list->get_item());
                    this->start_list->change_item(item);
                }
                this->start_list->change_next(this->end_list);
                break;
            }
            default : {
                if (item >= this->start_list->get_item()){
                    this->start_list->change_previous(new_one);
                    new_one->change_next(this->start_list);
                    this->start_list = new_one;
                } else {
                    if (item <= this->end_list->get_item()) {
                        this->end_list->change_next(new_one);
                        new_one->change_previous(this->end_list);
                        this->end_list = new_one;
                    } else {
                        Element<type_for_deck>* current = this->start_list;
                        while (item <= current->get_item())
                            current = current->get_next();
                        current = current->get_previous();
                        new_one->change_next(current->get_next());
                        new_one->get_next()->change_previous(new_one);
                        new_one->change_previous(current);
                        new_one->get_previous()->change_next(new_one);
                    }
                }
                break;
            }
        }
        ++this->n;
    }

    type_for_deck pop(){
        type_for_deck returner = this->end_list->get_item();
        switch (this->n) {
            case 2 :
            case 1 : {
                --this->n;
                this->start_list->change_next(nullptr);
                break;
            }
            case 0 : {
                --this->n;
                std::cout << "deck is empty";
                exit(0);
            }
            default : {
                --this->n;
                this->end_list = this->end_list->get_previous();
                delete this->end_list->get_next();
                this->end_list->change_next(nullptr);
                break;
            }
        }
        return returner;
    }

    type_for_deck peek(){ return this->end_list->get_item(); }
};

template <typename type_for_result, typename limit>
std::ostream& operator<<(std::ostream& strm, const priority_queue<type_for_result, limit>& result){
    strm << "   beginning of queue\n";
    if (result.n == 0)
        strm << "queue is empty\n";
    else {
        Element<type_for_result> *current = result.start_list;
        while (current != nullptr) {
            strm << "     " << current->get_item() << "\n";
            current = current->get_next();
        }
        strm << "   end of queue";
    }
    return strm;
}


#endif //LAB_10_CLASSES_H