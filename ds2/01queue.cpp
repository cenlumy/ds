#include <iostream>
using namespace std;

typedef int T;
#include "list01.h"
class Queue{
	List l;
public:
	Queue& push(const T& d){l.push_back(d);return *this;}
	T pop(){ T t = front(); l.erase(0); return t;}
	const T& front()const{ return l.front();}
	const T& back()const{ return l.back();}
	int size()const{return l.size();}
	void clear(){l.clear();}
	bool empty()const{return l.empty();}//通过判断链表是否为空去判断队列是否为空
	bool full()const{return false;}
};
int main()
{
	Queue q;
	q.push(1).push(2).push(3);
	q.push(4).push(5).push(6);
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	q.push(6).push(7).push(8);
	while(!q.empty())
		cout << q.pop() << endl;
}



