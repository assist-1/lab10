#include <iostream>
#include <string>
#include <typeinfo>

#define RAND_MAX 50000

class Point
{
  double x;
  double y;
  public:
    Point(): x(0), y(0) {}
    Point(float x, float y): x(x), y(y) {}
    void move (float x, float y) 
      {this->x+=x; this->y+=y;}
    float* get() {return new float[2]{x,y};}
    friend std::ostream& operator<< (std::ostream& out, Point point)
    {
      out << "(" << point.x << "; " << point.y << ")";
      return out;
    }
};


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
    ~MyDack();
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
MyDack<type>::~MyDack()
{
  while(first!=last)
  {
    
    first=first->next;
    delete first->prev;
  }
  if (length!=0) delete last;
  
  first=nullptr;
  last=nullptr;
}
  


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
    if (length!=1)
    {
      last= last->prev;
      delete (last->next);
      last->next=nullptr;
    }
    else 
    {
      delete last;
      last=nullptr; 
      first=nullptr;
    }
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
    if (length!=1)
    {
      first = first->next;
      delete (first->prev);
      first->prev=nullptr;
    }
    else
    {
      delete first;
      first=nullptr;
      last=nullptr;
    }
    --length;
    return tmp;    
  }
}

template<class type>
size_t MyDack<type>::size() const
{
  return length;
}




int main()
{
  float data[50];
  for (int i=0; i<50; ++i)
  {
    data[i] = rand()/1000000.;
  }
  MyDack<float> dack;
  std::cout << "data:\n";
  for (int i=0; i<10; ++i)
  {
    std::cout << data[i] << " ";
    dack.push_front(data[i]);
  }
  std::cout << "\n\npush front:\n" << dack 
  << "\npop_back:\n";
  for (int i=0; i<10; ++i)
  {
    std::cout << dack.pop_back() << " ";
  }
  std::cout << "\n\ndata:\n";
  for (int i=10; i<24; ++i)
  {
    std::cout << data[i] << " ";
    dack.push_back(data[i]);
  }
  std::cout << "\n\npush back:\n" << dack 
  << "\npop_front:\n";
  for (int i=0; i<14; ++i)
  {
    std::cout << dack.pop_back() << " ";
  }
  dack.~MyDack<float>();
  MyDack<Point> pack;
  std::cout << "\n\n\n!!!POINTS!!!\n\ndata:\n";
  for (int i=24; i<36; i+=2)
  {
    std::cout << data[i] << " " << data[i+1] << " ";
    Point a(data[i],data[i+1]);
    pack.push_front(Point(data[i],data[i+1]));
  }
  std::cout << "\n\npush front:\n" << pack
  << "\ndata:\n";
  for (int i=36; i<50; i+=2)
  {
    std::cout << data[i] << " " << data[i+1] << " | ";
    pack.push_back(Point(data[i],data[i+1]));
  }
  std::cout << "\n\npush back:\n" << pack
  << "\npop back:\n";
  for (int i=0; i<5; ++i)
  {
    std::cout << pack.pop_back() << " ";
  }
  std::cout << "\n\npop front:\n";
  for (int i=0; i<8; ++i)
  {
    std::cout << pack.pop_front() << " ";
  }
  pack.~MyDack<Point>();
      
} "\npop front:\n";
  for (int i=0; i<8; ++i)
  {
    std::cout << pack.pop_front() << " ";
  }
  //delete &pack;
      
}