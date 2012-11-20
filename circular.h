#include <iostream>
using namespace std;
template<class T>
class circhain;
template<class T>
class circhainNode{
friend circhain<T>;
private:
	T data;
	circhainNode<T> *link;
};
template<class T>
class circhain{
public:
	circhain()
	{
		first = new circhainNode<T>;
		first->link = first;
	}
	~circhain();
	bool IsEmpty()const
	{
		return first->link == first;
	}
	int Length()const;
	bool Find(int k,T &x)const;
	int Search(const T &x)const;
	circhain<T>& Delete(int k,T& x);
	circhain<T>& Insert(int k,const T& x);
	void Output(ostream& out)const;
private:
	circhainNode<T> *first;
};