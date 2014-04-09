#include <iostream>
using namespace std;

typedef int T;
#include "list01.h"
class Queue{
	T a[5];
	int b, n;//队首位置和有效元素的个数
public:
    Queue():b(0),n(0){};
	Queue& push(const T& d){
	if(full()) throw " already full";
	a[(b+n++)%5] = d;
	return *this;
	}
	T pop(){
		if(empty()) throw " already empty ";
		--n ; return a[(b++)%5];
	}
	const T& front()const{
		return a[b%5];
	}

	const T& back()const{
		return a[(b+n-1)%5];
	}
	int size()const{return b;}
	void clear(){b=0; n=0;}
	bool empty()const{ return n==0; }
	bool full()const{ return n==5; }
};
int main()
{
	Queue q;
	try{
//	cout << q.pop() << endl;
	q.push(1).push(2).push(3);
	q.push(4).push(5);
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	q.push(6).push(7).push(8);
	}
	catch(const char* e){
		cout << "exception:" << e << endl;
	}
	while(!q.empty())
		cout << q.pop() << endl;
}



