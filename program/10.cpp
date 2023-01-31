#include <iostream>
using namespace std;

template <class Type> class queueObject{
	public:
		queueObject* previousObject;
		queueObject* nextObject;
		Type value;
	
	public:
		queueObject(queueObject* lpreviousObject,queueObject* lnextObject){
			this->previousObject=lpreviousObject;
			this->nextObject=lnextObject;
			this->value=0;
		}	
		queueObject(queueObject* lpreviousObject,queueObject* lnextObject,int lvalue){
			this->previousObject=lpreviousObject;
			this->nextObject=lnextObject;
			this->value=lvalue;
		}
		~queueObject(){}
};



template <class qType> class queueOperator{
	public:
		queueObject<qType>* first = NULL;
		queueObject<qType>* last = NULL;
		int elementsInQueue = 0;
		
	public:
		queueOperator(){}
		~queueOperator(){}
		
		friend ostream& operator<< (ostream &out,queueOperator<qType> &queue);
		
		void push_back(qType item){
			if(elementsInQueue==0){
				queueObject<qType>* newObject = new queueObject<qType>(NULL,NULL,item);
				first = newObject;
				last = newObject;
				this->elementsInQueue++;
			}
			else{
				queueObject<qType>* newObject = new queueObject<qType>(last,NULL,item);
				this->last->nextObject = newObject;
				last = newObject;
				this->elementsInQueue++;
			}
		}
		qType pop_back(){
			if(elementsInQueue==0){
				cerr<<"Error:No elements in queue"<<endl;
				exit(0);
			}
			else{
				queueObject<qType>* tmp = last;
				this->last = this->last->previousObject;
				this->last->nextObject = NULL;
				qType tmpValue;
				tmpValue = tmp->value;
				delete tmp;
				this->elementsInQueue--;
				return tmpValue;
			}
		}
		
		void push_front(qType item){
			if(elementsInQueue==0){
				queueObject<qType>* newObject = new queueObject<qType>(NULL,NULL,item);
				first = newObject;
				last = newObject;
				this->elementsInQueue++;
			}
			else{
				queueObject<qType>* newObject = new queueObject<qType>(NULL,first,item);
				this->first->previousObject = newObject;
				first = newObject;
				this->elementsInQueue++;
			}
		}
		qType pop_front(){
			if(elementsInQueue==0){
				cerr<<"Error:No elements in queue"<<endl;
				exit(0);
			}
			else{
				queueObject<qType>* tmp = first;
				this->first = this->first->nextObject;
				this->first->previousObject = NULL;
				qType tmpValue;
				tmpValue = tmp->value;
				delete tmp;
				this->elementsInQueue--;
				return tmpValue;
			}
		}
		int size(){
			return this->elementsInQueue;
		}
};

template <class qType> ostream& operator<< (ostream &out,queueOperator<qType>* queue){
			out << "Queue:[";
			bool inQueue = true;
			queueObject<qType>* tmp = queue->first;
			while(inQueue){
				out << tmp->value <<' ';
				tmp = tmp->nextObject;
				if(tmp==queue->last)continue;
				if(tmp==NULL)break;
			}
			out<<']';
			return out;
}

int main(int argc,char** argv){
	queueOperator<int>* queue = new queueOperator<int>();
	queue->push_back(10);
	queue->push_back(20);
	queue->push_back(30);
	queue->push_back(1);
	queue->push_back(52);
	cout << queue <<" Size:"<<queue->size() <<endl;
	
	cout << queue->pop_back()<<endl;
	cout << queue<< " Size:"<<queue->size()<< endl;
	
	queue->push_front(111);
	queue->push_front(99);
	cout << queue<<" Size:"<<queue->size()<<endl;
	
	cout << queue->pop_front()<<endl;
	cout << queue <<" Size:"<<queue->size()<< endl;
	delete queue;
	
	cout << "_________________________________________________________" << endl;
	
	queueOperator<char>* queue1 = new queueOperator<char>();
	queue1->push_back('A');
	queue1->push_back('B');
	queue1->push_back('C');
	queue1->push_back('D');
	queue1->push_back('E');
	cout << queue1 <<" Size:"<<queue1->size()<< endl;
	
	cout << queue1->pop_back()<<endl;
	cout << queue1<<" Size:"<<queue1->size()<<endl;
	
	queue1->push_front('F');
	queue1->push_front('G');
	cout << queue1<<" Size:"<<queue1->size()<<endl;
	
	cout << queue1->pop_front()<<endl;
	cout << queue1 <<" Size:"<<queue1->size()<< endl;
	delete queue1;
	return 0;
}