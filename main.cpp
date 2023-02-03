#include <iostream>
#include <cmath>

template <typename T>
class PriorityQueue {
    T data_[100];
    int size_;

public:
    PriorityQueue() : size_(0) {}

    void push(const T& item) {
        data_[size_] = item;
        int index = size_;
        size_++;

        while (index > 0) {
            int parent = (index - 1);
            if (data_[index] >= data_[parent]) {
                break;
            }
            std::swap(data_[index], data_[parent]);
            index = parent;
        }
    }

    T pop() {
        T result = data_[0];
        size_--;
        data_[0] = data_[size_];

        int index = 0;
        while (true) {
            int left = index + 1;
            int right = index + 2;
            if (left >= size_) break;

            int min_child = (right >= size_ || data_[left] < data_[right]) ? left : right;
            if (data_[index] <= data_[min_child]) break;

            std::swap(data_[index], data_[min_child]);
            index = min_child;
        }
        return result;
    }

    const T& peek() const { return data_[0]; }

    friend std::ostream& operator<<(std::ostream& out, const PriorityQueue<T>& queue) {
        out << "[";
        for (int i = 0; i < queue.size_; i++) {
            out << queue.data_[i];
            if (i != queue.size_ - 1) out << ", ";
        }
        out << "]";
        return out;
    }

};

int main() {
    PriorityQueue<int> q;
    q.push(2);
    std::cout << q << std::endl;
    q.push(3);
    std::cout << q << std::endl;
    q.push(1);
    std::cout << q << std::endl;
    q.push(5);
    std::cout << q << std::endl;
    q.push(4);
    std::cout << q << std::endl;
    q.pop();
    std::cout << q << std::endl;
    q.pop();
    std::cout << q << std::endl;
    return 0;
}