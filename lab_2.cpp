#include<iostream>
template <typename T>
class MyBinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& d) : data(d), left(nullptr), right(nullptr) {}
    };
    Node* root;
public:
    MyBinaryTree() : root(nullptr) {}
    void push(const T& item) {
         root = insert(root, item);
     }
    void inOrder(Node* node, std::ostream& out) {
        if (node) {
            inOrder(node->left, out);
            out << node->data << " ";
            inOrder(node->right, out);
        }
    }
    ~MyBinaryTree() {
        clear(root);
    }
private:
    Node* insert(Node* node, const T& data) {
        if (!node) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }

        return node;
    }
    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    friend std::ostream& operator<<(std::ostream& out, MyBinaryTree<T>& bt){
    bt.inOrder(bt.root, out);
    return out;
    }
};

int main(){
MyBinaryTree<int> bst;
bst.push(5);
bst.push(3);
bst.push(7);
bst.push(1);
bst.push(9);

std::cout<< bst << std::endl;
}