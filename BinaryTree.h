#ifndef LABA10_BINARYTREE_H
#define LABA10_BINARYTREE_H

template <typename T>
class BinaryTree {
public:
    struct TreeElement {
        explicit TreeElement(T new_key) {
            key = new_key;
        }
        T key = 0;
        TreeElement *left_child = nullptr;
        TreeElement *right_child = nullptr;
    };

public:
    void Push(T el) {
        size_++;
        TreeElement **cur = &root;
        while (*cur != nullptr) {
            if ((*cur)->key < el) {
                cur = &(*cur)->right_child;
            }
            else if ((*cur)->key > el) {
                cur = &(*cur)->left_child;
            }
            else {
                return;
            }
        }
        *cur = new TreeElement(el);
    }

    size_t sizee(){
        return size_;
    }

private:
    TreeElement *root = nullptr;
    size_t size_ = 0;
};

template <typename T>
std::ostream& operator<<(std::ostream& stream, BinaryTree<T>& A){
    stream << "size of binary tree: " << A.sizee();
    return stream;
}


#endif //LABA10_BINARYTREE_H
