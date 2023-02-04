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
}


struct Tail
{
    Tail *prev;
    std::string str;
 
    Tail(Tail *prev, std::string str)
    {
        this->prev = prev;
        this->str = str;
    }
};
 
void showTails(Tail *p, std::ostream &out)
{
    if (p == nullptr) {
        return;
    }
 
    showTails(p->prev, out);
    out << p->str;
}


template<typename T>
void printTree(Node<T>* node, Tail *prev, bool isLeft, std::ostream& out)
{
    if (node == nullptr) {
        return;
    }

    std::string prev_str = "    ";
    Tail *tail = new Tail(prev, prev_str);
 
    printTree(node->pRight, tail, true, out);
 
    if (!prev) {
        tail->str = "────";
    }
    else if (isLeft)
    {
        tail->str = "┌───";
        prev_str = "    │";
    }
    else {
        tail->str = "└───";
        prev->str = prev_str;
    }
 
    showTails(tail, out);
    out << node->data << std::endl;
 
    if (prev) {
        prev->str = prev_str;
    }
    tail->str = "    │";
 
    printTree(node->pLeft, tail, false, out);
}


template<typename T>
std::ostream& operator<<(std::ostream& out, MyBinaryTree<T> tree) {
    printTree(tree.get_head(), nullptr, false, out);
    return out;
}



template<typename T>
MyBinaryTree<T>::~MyBinaryTree()
{
}



int main() {

    MyBinaryTree<int> tree;
    tree.push(10);
    tree.push(5);
    tree.push(15);
    tree.push(20);
    tree.push(12);
    tree.push(7);
    tree.push(2);
    tree.push(1);
    tree.push(4);
    tree.push(17);
    tree.push(2);
    tree.push(0);    
    tree.push(25);
    tree.push(5);
    tree.push(3);
    tree.push(4);

    std::cout << tree;

    return 0;
}