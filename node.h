template <typename T>
class Node
{
public:
    Node(T, Node*, bool);
    Node(T);
    Node<T>* pr_head = nullptr;
    Node<T>* pr_tail = nullptr;
    T value;
};

template <typename T>
Node<T>::Node(T item, Node<T>* node, bool head)
{
    value = item;
    if(!head) pr_head = node;
    else      pr_tail = node;
}

template <typename T>
Node<T>::Node(T item)
{
    value = item;
}