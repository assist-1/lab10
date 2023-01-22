#include <iostream>
#include <cstring>

template<class type>
struct elem {
  type value;
  struct elem *next;
};

// виртуальный класс очереди

template<class type>
class queue {
 public:
  virtual size_t size() = 0;
  virtual void push(type) = 0;
  virtual type pop() = 0;
  virtual void peek() = 0;
};

// добавление в конец очереди, удаление из конца очереди

template<class type>
class queueMax : public queue<type> {
 protected:
  struct elem<type> *last;
  size_t count = 0;
 public:
  struct elem<type> *first;
  size_t size() override;
  void push(type) override;
  type pop() override;
  void peek() override;
};

template<class type>
void queueMax<type>::push(type value) {
  struct elem<type> *temp, *comp, *prev;
  temp = (struct elem<type> *) malloc(sizeof(struct elem<type>));
  temp->value = value;
  if (count == 0) {
    temp->next = nullptr;
    first = temp;
    last = temp;
  } else {
    comp = first;
    while (temp->value > comp->value) {
      comp = comp->next;
      if (comp == nullptr) {
        break;
      }
    }
    if (comp == nullptr) {
      temp->next = nullptr;
      last->next = temp;
      last = temp;
    } else if (comp == first) {
      temp->next = first;
      first = temp;
    } else {
      prev = first;
      while (prev->next != comp) {
        prev = prev->next;
      }
      temp->next = comp;
      prev->next = temp;
    }
  }
  ++count;
}

template<class type>
type queueMax<type>::pop() {
  if (count == 0) {
    std::cerr << "Error: Arrive is empty." << std::endl;
    return 0;
  } else {
    struct elem<type> *temp;
    type value = last->value;
    temp = first;
    while (temp->next != last) {
      temp = temp->next;
    }
    free(last);
    temp->next = nullptr;
    last = temp;
    --count;
    return value;
  }
}

template<class type>
void queueMax<type>::peek() {
  if (count == 0) {
    std::cerr << "Error: Arrive is empty." << std::endl;
  } else {
    struct elem<type> *temp;
    type value = last->value;
    temp = first;
    while (temp->next != last) {
      temp = temp->next;
    }
    free(last);
    temp->next = nullptr;
    last = temp;
    --count;
  }
}

template<class type>
size_t queueMax<type>::size() {
  return count;
}

// добавление в начало очереди, удаление из начала очереди

template<class type>
class queueMin : public queue<type> {
 protected:
  struct elem<type> *last;
  size_t count = 0;
 public:
  struct elem<type> *first;
  size_t size() override;
  void push(type) override;
  type pop() override;
  void peek() override;
};

template<class type>
void queueMin<type>::push(type value) {
  struct elem<type> *temp, *comp, *prev;
  temp = (struct elem<type> *) malloc(sizeof(struct elem<type>));
  temp->value = value;
  if (count == 0) {
    temp->next = nullptr;
    first = temp;
    last = temp;
  } else {
    comp = first;
    while (temp->value < comp->value) {
      comp = comp->next;
      if (comp == nullptr) {
        break;
      }
    }
    if (comp == nullptr) {
      temp->next = nullptr;
      last->next = temp;
      last = temp;
    } else if (comp == first) {
      temp->next = first;
      first = temp;
    } else {
      prev = first;
      while (prev->next != comp) {
        prev = prev->next;
      }
      temp->next = comp;
      prev->next = temp;
    }
  }
  ++count;
}

template<class type>
type queueMin<type>::pop() {
  if (count == 0) {
    std::cerr << "Error: Arrive is empty." << std::endl;
    return 0;
  } else {
    struct elem<type> *temp;
    type value = first->value;
    temp = first->next;
    free(first);
    first = temp;
    --count;
    return value;
  }
}

template<class type>
void queueMin<type>::peek() {
  if (count == 0) {
    std::cerr << "Error: Arrive is empty." << std::endl;
  } else {
    struct elem<type> *temp;
    type value = first->value;
    temp = first->next;
    free(first);
    first = temp;
    --count;
  }
}

template<class type>
size_t queueMin<type>::size() {
  return count;
}

// перегрузка оператора <<

template<class type>
std::ostream &operator<<(std::ostream &ostream, queueMax<type> &queue_max) {
  struct elem<type> *temp;
  temp = queue_max.first;
  for (size_t i = 0; i < queue_max.size(); ++i) {
    ostream << temp->value << " ";
    temp = temp->next;
  }
  return ostream;
}

template<class type>
std::ostream &operator<<(std::ostream &ostream, queueMin<type> &queue_min) {
  struct elem<type> *temp;
  temp = queue_min.first;
  for (size_t i = 0; i < queue_min.size(); ++i) {
    ostream << temp->value << " ";
    temp = temp->next;
  }
  return ostream;
}

int main() {
  queueMax<int> queue_max;
  queueMin<int> queue_min;

  queue_max.push(5);
  queue_max.push(1);
  queue_max.push(2);
  queue_max.push(4);
  queue_max.push(3);
  int pop_max;
  pop_max = queue_max.pop();
  queue_max.peek();

  std::cout << "elem: " << queue_max << "| size: " << queue_max.size() << " | " << "pop: " << pop_max << std::endl;

  queue_min.push(1);
  queue_min.push(4);
  queue_min.push(2);
  queue_min.push(3);
  queue_min.push(5);
  int pop_min;
  pop_min = queue_min.pop();
  queue_min.peek();

  std::cout << "elem: " << queue_min << "| size: " << queue_min.size() << " | " << "pop: " << pop_min << std::endl;

  return 0;
}
