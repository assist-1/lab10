#include <iostream>


template<typename T>
class Node
    {
    public:
        Node *pLeft;
        Node *pRight;
        T data;

        Node(T data, Node *pLeft = nullptr, Node *pRight = nullptr)
        {
            this->pLeft = pLeft;
            this->pRight = pRight;
            this->data = data;
        }
};


template<typename T>
class MyBinaryTree
{
    private:
        int size;
        Node<T> *head;


    public:
        MyBinaryTree();
        ~MyBinaryTree();
        
        void push(T data);
        int get_size() {return size;}

        Node<T> *get_head() { return head; }
};


template<typename T>
MyBinaryTree<T>::MyBinaryTree()
{
    size = 0;
    head = nullptr;
}

template<typename T>
void MyBinaryTree<T>::push(T data)
{
    if (head == nullptr) head = new Node<T>(data);
    else {
        Node<T> *current = head;
        while (true) {
            if (data <= current->data) {
                if (current->pLeft != nullptr) current = current->pLeft;
                else {
                    current->pLeft = new Node<T>(data);      
                    break;
                }    
            } 

            else {
                if (current->pRight != nullptr) current = current->pRight;
                else {
                    current->pRight = new Node<T>(data);
                    break;
                }
            }
        }
    }
    size += 1;
}






template<typename T>
MyBinaryTree<T>::~MyBinaryTree()
{
    
}



int main() {

    MyBinaryTree<int> tree;
    tree.push(10);
    tree.push(9);
    tree.push(12);
    tree.push(10);
    
    tree.push(5);
    tree.push(2);
    tree.push(15);
    tree.push(3);
    tree.push(11);

    std::cout << tree;

    return 0;
}