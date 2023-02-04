#include <iostream>
#include <map>
#include <cmath>
using std::cout;
using std::endl;
using std::ostream;
using std::map;
using std::string;

template <typename T>
class BinTree{
    private:
    map<int, T> d;
    int n;
    int length;
    public:
    BinTree(){
        n = 0;
        length = 0;
    }void push(T a){
        bool flag = true;
        int temp = 0;
        int i = 0;
        while (flag){
            if (d.count(temp) == 0){
                d[temp] = a;
                flag = false;
            }else{
                if (a >= d[temp]) temp = temp * 2 + 2;
                else temp = temp * 2 + 1;
            }i++;
        }if (i > n) n = i;
    }int get_depth(){return n;}
    T get_sign(int a){
        if (d.count(a)) return d[a];
    }bool included(int a){return d.count(a);}
};

template <typename T>
ostream &operator<<(ostream &out, BinTree<T> b){
    int l = b.get_depth();
    for (int i = 0; i < l; i++){
        for (int j = 0; j < pow(2, i); j++){
            string s(pow(2, l - i - 1) - 1, ' ');
            out << s;
            if (b.included(pow(2, i) + j - 1)) out << b.get_sign(pow(2, i) + j - 1);
            else out << ".";
            out << s << " ";
        }out << endl;
    }return out;
}

int main()
{
    BinTree<int> a;
    a.push(4);
    a.push(5);
    a.push(6);
    a.push(7);
    a.push(8);
    a.push(9);
    a.push(10);
    cout << a << endl << endl;
    BinTree<char> b;
    b.push('a');
    b.push('b');
    b.push('c');
    b.push('d');
    cout << b;
}
