#include <iostream>
#include "bin_tree.h"
#include <string>

using namespace std;
using std::string;

int main() {
    BinTree<int> bt(2);

    bt.Push(3);
    bt.Push(1);
    bt.Push(6);
    bt.Push(5);
    cout << bt << endl;

    BinTree<string> bt1("Ivanov");
    bt1.Push("Petorv");
    bt1.Push("Aconov");
    cout << bt1 << endl;
}