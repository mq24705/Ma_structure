#ifndef CIRCULAR__H_
#define CIRCULAR__H_
#include"circular.h"
class NoMem{
public:
	NoMem(){}
};
void my_new_handler()
{
	throw NoMem();
}
new_handler Old_Handler_ = set_new_handler(my_new_handler);
class OutOfBounds{
public:
	OutOfBounds(){}
};
template<class T>
circhain<T>::~circhain()
{
	circhainNode<T> *next;
	circhainNode<T> *fnode = first;
	first = first->link;
	while( first != fnode){
		next = first->link;
		delete first;
		first = next;
	}

	delete first;
}
template<class T>
int circhain<T>::Length() const
{
	circhainNode<T> *current = first->link;
	int index = 0;
	while(current != first){
		current = current->link;
		index++;
	}
	return index;
}
template<class T>
bool circhain<T>::Find(int k,T& x)const
{
	if(k < 1)
		return false;
	circhainNode<T> *current = first->link;
	int index = 1;
	while(index < k && current != first){
		current = current->link;
		index++;
	}
	if(current == first)
		return false;
	else{
		x = current->data;
		return true;
	}
}
template<class T>
int circhain<T>::Search(const T& x)const
{
	circhainNode<T> *current = first->link;
	first->data = x;
	int index = 1;
	while(current->data != x){
		current = current->link;
		index++;
	}
	return (current == first) ? 0 : index;
}
template<class T>
circhain<T>& circhain<T>::Delete(int k,T& x)
{
	if(k < 1 || first == first->link)
		throw OutOfBounds();
	circhainNode<T> *p = first->link;
	if(k == 1)
		first->link = p->link;
	else{
		circhainNode<T> *q = first->link;
		for(int index = 1; index < k - 1 && q != first;index++)
			q = q->link;
		if(q == first || q->link == first)
			throw OutOfBounds();
		p = q->link;
		if(p->link == first){
			q->link = first;
		}else
			q->link = p->link;
	}
	x = p->data;
	delete p;
	return *this;
}
template<class T>
circhain<T>& circhain<T>::Insert(int k,const T& x)
{
	if(k < 0)
		throw OutOfBounds();
	circhainNode<T> *p = first->link;
	for(int index = 1; index < k && p != first;index++)
		p = p->link;
	if(k > 0 && p == first)
		throw OutOfBounds();
	circhainNode<T> *q = new circhainNode<T>;
	q->data = x;
	if(k){
		q->link = p->link;
		p->link = q;
	}else{
		q->link = first->link;
		first->link = q;
	}
	return *this;
}
template<class T>
void circhain<T>::Output(ostream& out)const
{
	circhainNode<T> *current = first->link;
	while(current != first){
		out << current->data << " ";
		current = current->link;
	}
	/*circhainNode<T> *current;
	for(current = first->link;current != first;current = current->link)
		cout << current->data << " ";*/
}
template<class T>
ostream& operator<<(ostream& out,const circhain<T>& x)
{
	x.Output(out);
	return out;
}
void main()
{
	int a;
	try{
		circhain<int> L;
		cout << "Length = " << L.Length() << endl;
		cout << "IsEmpty = " << L.IsEmpty() << endl;
		L.Insert(0,2).Insert(1,6);
		cout << "List is " << L << endl;
		cout << "IsEmpty = " << L.IsEmpty() << endl;
		int z;
		L.Find(1,z);
		cout << "First element is" << z << endl;
		cout << "Length = " << L.Length() << endl;
		L.Delete(1,z);
		cout << "delted element is" << z << endl;
		cout << "List is " << L << endl;
		
	}
	catch(...){
		cerr << "An exception has occurred" << endl;
	}
	cin >> a;
}
#endif