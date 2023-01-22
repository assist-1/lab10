#include <iostream>
using std::cout;
using std::endl;
template <typename T>
class MyDeck {
    struct obj {
        T item;
        obj* next;
        obj* pre;
        obj(T item) {
            this->item = item;
            next = NULL;
            pre = NULL;
        }
    };
    int size_deck = 0;
    obj* begin;
    obj* end;

public:
    MyDeck() {
        size_deck = 0;
        begin = NULL;
        end = NULL;
    };
    obj* push_back(T item) {
        obj* trm = new obj(item);
        if (size_deck == 0) {
            begin = trm;
        }
        else {
            end->next = trm;
            trm->pre = end;
        }
        end = trm;
        size_deck += 1;
        return trm;
    }
    obj* push_front(T item) {
        obj* trm = new obj(item);
        if (size_deck == 0) {
            begin = trm;
            end = trm;
        }
        else {
            trm->next = begin;
            begin->pre = trm;
            begin = trm;
        }
        size_deck += 1;
        return trm;
    }
    T pop_back() {
        if (size_deck == 0) {
            cout << "Deck is empty" << endl;
        }
        else if (size_deck == 1) {
            T ans;
            ans = end->item;
            begin = NULL;
            end = NULL;
            size_deck = 0;
            return ans;
        }
        else {
            T ans;
            ans = end->item;
            obj* trm = end->pre;
            trm->next = NULL;
            delete end;
            end = trm;
            size_deck -= 1;
            return  ans;
        }
    }
    T pop_front() {
        if (size_deck == 0) {
            cout << "Deck is empty" << endl;
        }
        else if (size_deck == 1) {
            T ans;
            ans = begin->item;
            begin = NULL;
            end = NULL;
            size_deck = 0;
            return ans;
        }
        else {
            T ans;
            ans = begin->item;
            obj* trm = begin->next;
            trm->pre = NULL;
            delete begin;
            begin = trm;
            size_deck -= 1;
            return  ans;
        }
    }
    int const size() {
        return size_deck;
    }
    friend std::ostream& operator<<(std::ostream& out, const MyDeck& A) {
        if (A.size_deck == 0) {
            out << "Deck is empty" << endl;
            return out;
        }
        else {
            obj* trm = A.begin;
            out << "Deck = { ";
            while (trm != A.end) {
                out << trm->item << ", ";
                trm = trm->next;
            }
            out << trm->item << " }\n";
        }
    };
};

int main()
{
    MyDeck<int> one;
    cout << one;
    for (int i = 1; i < 20; i += 7) {
        one.push_back(i);
        one.push_front(i);
    }
    cout << one;
    cout << "Size of deck = " << one.size() << endl;
    cout << "pop_front() = " << one.pop_front() << endl;
    cout << one;
    cout << "pop_back() = " << one.pop_back() << endl;
    cout << one;
    cout << '\n';


    MyDeck<char> two;
    two.push_back('i');
    two.push_front('c');
    two.push_back('A');
    two.push_front('3');
    cout << two;
    cout << "Size of deck = " << two.size() << endl;
    cout << "pop_front() = " << two.pop_front() << endl;
    cout << two;
    cout << "pop_back() = " << two.pop_back() << endl;
    cout << two;
    cout << '\n';
    return 0;
}

