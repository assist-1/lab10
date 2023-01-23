/*
Реализовать шаблонный класс, соответствующий варианту.
Перегрузить оператор <<, который помещает объект вашего класса в поток в удобочитаемом виде.

Работу методов класса следует проиллюстрировать в main.
Вариант 0: MyBinaryTree

Основной функционал: push(item) — добавляет элемент в дерево.

Описание, принцип работы: Бинарное дерево — это упорядоченное дерево, каждая вершина которого имеет не более двух поддеревьев, причём для каждого узла выполняется правило: в левом поддереве содержатся только ключи, имеющие значения, меньшие, чем значение данного узла, а в правом поддереве содержатся только ключи, имеющие значения, большие, чем значение данного узла.
*/

#include <iostream>

using std::ostream;
using std::string;
using std::cin;
using std::cout;

template <class T>
struct Node {  //структура узла дерева
    T key;

    Node * parent = NULL; //родитель

    Node * left = NULL; //дети
    Node * right = NULL;

    Node (T data) {
        key = data; //значение
    }
};

template <class T>
class BTree { //класс бинарного дерева
public:
    Node<T> * root = NULL;

    BTree();
    ~BTree();

    void push(T);
    void print_tree(Node<T> * subroot, const string& prefix, bool is_left = false);
    void clear_tree(Node<T> *);
};

template <class T>
ostream& operator<<(ostream&, BTree<T>&); //для вывода дерева

//=====================================

int main() 
{
    long int number_of_nodes;
    cin >> number_of_nodes;
  
    BTree<int> * btree = new BTree<int>(); 
  //создаём пример дерева с целыми числами
    int tmp;

    for (int i = 0; i < number_of_nodes; ++i) {
        cin >> tmp;
        btree->push(tmp); //добавляем элементы
    }

  cout << * btree; //вывод дерева

    return 0;
}

//=====================================

template <class T>
BTree<T>::BTree() { //конструктор
  root = NULL;
}

template <class T>
BTree<T>::~BTree() { //деструктор
  clean_tree(root);
}
  
template <class T>
void BTree<T>::push(T data) { //добавление элемента
  
    if (root == NULL) {
        root = new Node<T>(data);
        return;
    }

    Node<T> * subroot = root; 
    Node<T> * parent = NULL;

    while (subroot != NULL) { //ищем место вставки
        parent = subroot;
        (subroot->key <= data) ? subroot = subroot->right : subroot = subroot->left;
    }

    Node<T> * buffer = new Node<T>(data); //новый узел

    (parent->key <= data) ? parent->right = buffer : parent->left = buffer; //вставка
}

template <class T>
void BTree<T>::clear_tree(Node<T> * curroot) { //рекурсивное удаление дерева
    if (curroot->left != NULL) {
        clear_tree(curroot->left);
    }

    if (curroot->right != NULL) {
        clear_tree(curroot->right);
    }

    delete curroot;
}

template <class T>
void BTree<T>::print_tree(Node<T> * subroot, const string & prefix, bool is_left) { //рекурсивная печать дерева
    if (subroot == NULL) {
        return;
    }
  cout << prefix;
  cout << (is_left ? "├──" : "└──" );

  cout << subroot->key << std::endl; //печать значения

  //поддеревья
    if (subroot->left != NULL) { 
        print_tree(subroot->left, prefix + (is_left ? "│   " : "    "), true);
    }
    if (subroot->right != NULL) {
        print_tree(subroot->right, prefix + (is_left ? "│   " : "    "), false);
    }
}

template <class T>
ostream& operator<<(ostream& os, BTree<T> &tree) {
  tree.print_tree(tree.root, ""); //вызов функции печати дерева
  return os;
}