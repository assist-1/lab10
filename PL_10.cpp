#include <iostream>
#include <typeinfo>
//using namespace std;

//Compiler version g++ 6.3.0

template <class type>
class MyDack
{
  
  struct items
  {
    items* next;
    items* prev;
    type item;
    items(type item): item(item), next(nullptr), prev(nullptr){};
    ~items() {next = nullptr; prev = nullptr;}
  };
  items* first;
  items* last;
  size_t length;
  
  public:
    MyDack();
    void push_front(type);
    void push_back(type);
    type pop_front();
    type pop_back();
    size_t size() const;
    friend std::ostream& operator<< (std::ostream& out, const MyDack& dack)
    {
      items* cur;
      cur = dack.first;
      out << "[" << cur->item;
      while(cur->next!=nullptr)
      {
        cur=cur->next;
        out << ", " << cur->item;
      }
      out << "]\n";
      return out;
    }
};

template<class type>
MyDack<type>::MyDack(): first(nullptr), last(nullptr), length(0) {}

template<class type>
void MyDack<type>::push_front(type item)
{
  items* tmp = new items(item);
  if (length==0) first = tmp;
  else
  {
    last->next=tmp;
    tmp->prev=last;
  }
  last = tmp;
  ++length;
}

template<class type>
void MyDack<type>::push_back(type item)
{
  items* tmp = new items(item);
  if (length==0) last = tmp;
  else
  {
    first->prev = tmp;
    tmp->next = first;
  }
  first = tmp;
  ++length;
}

template<class type>
type MyDack<type>::pop_front()
{
  if (length==0) std::cerr << "Dack is empty.\n";
  else
  {
    type tmp = last->item;
    last= last->prev;
    delete (last->next);
    last->next=nullptr;
    --length;
    return tmp;    
  }
}

template<class type>
type MyDack<type>::pop_back()
{
  if (length==0) std::cerr << "Dack is empty.\n";
  else
  {
    type tmp = first->item;
    first = first->next;
    delete (first->prev);
    first->prev=nullptr;
    --length;
    return tmp;    
  }
}

template<class type>
size_t MyDack<type>::size() const
{
  return length;
}



template<class type>
void fill (MyDack<type>& dack)
{
  type a;
  bool flag = true;
  std::cout << "enter " << typeid(a).name() << " data (0 for stop):\n";
    while (flag||(a!=0))
    {
      flag = false;
      std::cin >> a;
      if (a==0) break;
      dack.push_front (a);
    }
}


int main()
{
    //MyDack<int> dack;
    //MyDack<float> dack;
    fill (dack); 
    std::cout << dack;    
}