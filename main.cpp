#include <iostream>

template <typename T>
class MyBinaryTree {
    struct Node {
        Node *left;
        Node *right;
        T value;
        Node(T n = 0, Node* l = 0, Node* r = 0) : value(n), left(l), right(r) {}
    };

    Node *root;
    
public:
    MyBinaryTree() { root = NULL; }
    ~MyBinaryTree() {}
    void push(Node *&tmp, T item);
    void push(T item);
    void print_tree(const std::string& str, Node *&tmp, bool is_right);
    void print_tree();

    friend std::ostream& operator<<(std::ostream& out, MyBinaryTree<T> tree) {
        tree.print_tree("", tree.root, false);
        return out;
    }
};

template <typename T>
void MyBinaryTree<T>::push(Node *&tmp, T item) {
    if (tmp == NULL) tmp = new Node(item);
    else {
        if (item < tmp->value) push(tmp->left, item);
        else push(tmp->right, item);
    }
}

template <typename T>
void MyBinaryTree<T>::push(T item) {
	push(root, item);
}

template<typename T>
void MyBinaryTree<T>::print_tree(const std::string& str, Node *&tmp, bool is_right) {
    if (tmp != NULL) {
        std::cout << str        << (is_right ? "├───" : "└───") 
                  << tmp->value << std::endl;

        print_tree(str + (is_right ? "|   " : "    "), tmp->right, true);
        print_tree(str + (is_right ? "|   " : "    "), tmp->left, false);
    }
}

template <typename T>
void MyBinaryTree<T>::print_tree() {
    print_tree("", root, false);
}



int main() {

    MyBinaryTree<int> tree;
    
	tree.push(6);
	tree.push(4);
    tree.push(5);
	tree.push(7);
	tree.push(10);
	tree.push(1);
	tree.push(2);
    tree.push(6);
    tree.push(-3);

    /*
    std::cout << "Вывод дерева через функцию класса :" << std::endl;
    tree.print_tree();
    std::cout << std::endl;
    */
    
    std::cout << "Вывод дерева через перегруженный оператор :" << std::endl;
    std::cout << tree << std::endl;

    return 0;
}