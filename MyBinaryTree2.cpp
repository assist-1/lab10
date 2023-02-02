#include <iostream>
#include <cmath>

using std::cout;

template <class N>
class Node{
private:
    N data;
    Node *right;
    Node *left;
public:
    Node(N data){
        this->data=data;
        right=nullptr;
        left=nullptr;
    }
    ~Node(){
        delete this->getLeft();
        delete this->getRight();
    }
    void push(int data){
        if((this->data)<data){
            if (right==nullptr){
                right=new Node<N>(data);
            }
            else{
                right->push(data);
            }
        }
        else if (this->data>data){
            if (left==nullptr){
                left=new Node<N>(data);
            }
            else{
                left->push(data);
            }
        }
        else{
            cout<<"Операция прервана, тк использовался уже имеющийся элемент в дереве";
        }
    }
    Node<N>* getRight(){
    return right;
    }
    Node<N>* getLeft(){
    return left;
    }
    N getValue(){
    return this->data;
    }
};

template <class T>
class BinTree{
private:
    Node<T> *firstElem;
public:
    BinTree(T data){
        firstElem=new Node<T>(data);
    }
    ~BinTree(){
        delete this->getFirstElem();
    }
    /*~BinTree(){
        cout<<"Зашли в деструктор\n";
        int level=1;
        int lamount=0;
        int sizel=2;
        Node<T> **nAlist=new Node<T>*[sizel];
        Node<T> **chetAlist=new Node<T>*[sizel*2];
        Node<T> *root=this->getFirstElem();
        if (root->getLeft()!=nullptr){
            nAlist[0]=root->getLeft();
            lamount++;
        };
        if (root->getRight()!=nullptr){
            nAlist[1]=root->getRight();
            lamount++;
        };
        delete root;
        while(lamount!=0){
            lamount=0;
            level++;
            int index=0;
            for (int i=0;i<sizel;i++){
                cout<<"Уровень :"<<level<<"\n";
                if (level%2==0){
                    if (nAlist[i]==nullptr){
                        //os<<level<<"."<<i+1<<":(-)   ";
                        //if (i+1==pow(2,level)){os<<"\n";}
                        chetAlist[index]=nullptr;
                        index++;
                        chetAlist[index]=nullptr;
                        index++;
                    }
                    else{
                        chetAlist[index]=nAlist[i]->getLeft();
                        if(chetAlist[index]!=nullptr){lamount++;}
                        index+=1;
                        //os<<level<<"."<<i+1<<":("<<(nAlist[i]->getValue())<<")  ";
                        chetAlist[index]=nAlist[i]->getRight();
                        if(chetAlist[index]!=nullptr){lamount++;};
                        index+=1;
                        delete nAlist[i];
                    }
                }
                else{
                    if (chetAlist[i]==nullptr){
                        //os<<level<<"."<<i+1<<":(-)   ";
                        //if (i+1==pow(2,level)){os<<"\n";}
                        nAlist[index]=nullptr;
                        index++;
                        nAlist[index]=nullptr;
                        index++;
                    }
                    else{
                        nAlist[index]=chetAlist[i]->getLeft();
                        if(nAlist[index]!=nullptr){lamount++;};
                        index+=1;
                        //os<<level<<"."<<i+1<<":("<<(chetAlist[i]->getValue())<<")   ";
                        nAlist[index]=chetAlist[i]->getRight();
                        if(nAlist[index]!=nullptr){lamount++;};
                        index+=1;
                        delete chetAlist[i];
                    }
                }
            };
            sizel*=2;
            if (level%2==0){
                delete [] nAlist;
                nAlist=new Node<T>*[sizel*2];
            }
            else{
                delete [] chetAlist;
                chetAlist=new Node<T>*[sizel*2];
            }
            //os<<"\n";
        };
        delete []nAlist;
        delete []chetAlist;
    }*/
    void push(int data){
        //cout<<"\nЗапущен пуш \n \n";
        firstElem->push(data);
        //cout<<"\nЗавершен пуш \n \n";
  }
  Node<T>* getFirstElem(){
    return firstElem;
  }
};

template <typename D>
std::ostream& operator << (std::ostream &os, BinTree<D> &p)
{
    os<<"1.1:("<<p.getFirstElem()->getValue()<<")\n";
    //int root=p.getFirstElem()->getValue();
    int level=1;
    int lamount=0;
    int sizel=2;
    Node<D> **nAlist=new Node<D>*[sizel];
    Node<D> **chetAlist=new Node<D>*[sizel*2];
    Node<D> *root=p.getFirstElem();
    if (root->getLeft()!=nullptr){
        nAlist[0]=root->getLeft();
        lamount++;
    };
    if (root->getRight()!=nullptr){
        nAlist[1]=root->getRight();
        lamount++;
    };
    while(lamount!=0){
        lamount=0;
        level++;
        int index=0;
        for (int i=0;i<sizel;i++){
            if (level%2==0){
                if (nAlist[i]==nullptr){
                    os<<level<<"."<<i+1<<":(-)   ";
                    if (i+1==pow(2,level)){os<<"\n";}
                    chetAlist[index]=nullptr;
                    index++;
                    chetAlist[index]=nullptr;
                    index++;
                }
                else{
                    chetAlist[index]=nAlist[i]->getLeft();
                    if(chetAlist[index]!=nullptr){lamount++;}
                    index+=1;
                    os<<level<<"."<<i+1<<":("<<(nAlist[i]->getValue())<<")  ";
                    chetAlist[index]=nAlist[i]->getRight();
                    if(chetAlist[index]!=nullptr){lamount++;};
                    index+=1;
                }
            }
            else{
                if (chetAlist[i]==nullptr){
                    os<<level<<"."<<i+1<<":(-)   ";
                    if (i+1==pow(2,level)){os<<"\n";}
                    nAlist[index]=nullptr;
                    index++;
                    nAlist[index]=nullptr;
                    index++;
                }
                else{
                    nAlist[index]=chetAlist[i]->getLeft();
                    if(nAlist[index]!=nullptr){lamount++;};
                    index+=1;
                    os<<level<<"."<<i+1<<":("<<(chetAlist[i]->getValue())<<")   ";
                    nAlist[index]=chetAlist[i]->getRight();
                    if(nAlist[index]!=nullptr){lamount++;};
                    index+=1;
                }
            }
        };
        sizel*=2;
        if (level%2==0){
            delete [] nAlist;
            nAlist=new Node<D>*[sizel*2];
        }
        else{
            delete [] chetAlist;
            chetAlist=new Node<D>*[sizel*2];
        }
        os<<"\n";
    };
    delete []nAlist;
    delete []chetAlist;
    return os;
}

int main(){
    setlocale(LC_ALL, "Russian");
    char a='c';
    BinTree<char> first(a);
    first.push('A');
    first.push('B');
    first.push('a');
    first.push('f');
    int b=100;
    BinTree<int> second(b);
    second.push(50);
    second.push(120);
    second.push(40);
    second.push(60);
    second.push(10);
    second.push(5);
    second.push(15);
    second.push(105);
    second.push(103);
    second.push(104);
    second.push(109);
    second.push(108);
    second.push(130);
    second.push(150);
    second.push(160);
    cout<<first;
    cout<<second;
    return 0;
}
