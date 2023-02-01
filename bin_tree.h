#include <iostream>
#include <string>

using namespace std;
using std::string;

template<typename T>
class BinTree {
    public:
        T value;
        BinTree* left;
        BinTree* right;
        BinTree(T val) {
            this->value = val;
            this->left = NULL;
            this->right = NULL;

        };
        void Push(T val) {
               if (val > value) {
                if (right != NULL) {
                    right->Push(val);
                } else {
                    BinTree* b = new BinTree(val);
                    right = b;
                }
            } else {
                if (left != NULL) {
                    left->Push(val);
                } else {
                    BinTree* b1 = new BinTree(val);
                    left = b1;
                }
            }
        };

        friend ostream& operator<<(ostream& os, const BinTree<T>& bt) {
            os << "{ __" << bt.value << "__";
            os << " left: ";
            if (bt.left != NULL) {
                os << *(bt.left);
                } else {
                    os << "empty";
                }

            os << " | right: ";

            if (bt.right != NULL) {
                os << *(bt.right);
                } else {
                    os << "empty";
                }

            os << " }";
            return os;

        };
        
};