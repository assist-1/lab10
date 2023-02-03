#include<iostream>
#include<cmath>

using namespace std;

template<typename t>
class binTree{
private:
  t task[1000] {0};
  int size = 0;
public:
  binTree(){};
  void push(t in){
    int i = 1;
    int count = 0;
    while(!(task[i] == 0)){
      if (in > task[i]){
        i = 2*i + 1;
        ++count;
      }else{
        i = 2 * i;
        ++count;
      }
    }
    task[i] = in;
    size = max(size, count);
  }

  int siz(){
    return size;
  }

  t pr(int i){
    return task[i];
  }
};

template<typename t>
std::ostream& operator<<(std::ostream &out, binTree<t> tree){
  int len = pow(2,tree.siz());
  for(int i = 0; i <= tree.siz(); ++i){
    for(int k = 0; k < len / pow(2,i); ++k){
      out << " ";
    }
    for(int j = pow(2,i); j < pow(2,i+1); ++j){
      if (tree.pr(j) == 0){
        out << " ";
      }else{
        out << tree.pr(j);
      }
      for(int k = 0; k < len / pow(2,i-1) - 1; ++k){
        out << " ";
      }
    }
    out << endl;
  }
}


int main(){
  binTree<int> example;
  example.push(4);
  example.push(2);
  example.push(6);
  example.push(1);
  example.push(3);
  example.push(5);
  example.push(7);
  cout << example;
  return 0;
}
