#include <iostream>
using namespace std;
#include <string>
typedef int T;
#include "list01.h"
class Stack{
	List l;
public:
	void push(const T& d); // 数据入栈成为栈顶
	T pop(); //栈顶数据出栈
	const T& top()const; // 取得栈顶数据
	bool empty()const; // 是否为空栈
	bool full()const{return false;} // 是否满栈 
	void clear(){l.clear();} //栈清空（复位）
	int size()const{return l.size();}// 栈中数据个数
};
void Stack::push(const T& d){
	l.push_front(d);
}
T Stack::pop(){ 
	T t = l.front();
	l.erase(0);
	return t;
}
const T& Stack::top()const{
	return l.front();
}
bool Stack::empty()const{
	return l.empty();//是否是空栈就还成判断是否为空的链表
}

int main()
{	
	Stack s;
	try{
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	}
	catch(const char* e){
		cout << " exception :" << e << endl;
	}
	while(!s.empty()){
		cout << s.pop() << endl;
	}
}
