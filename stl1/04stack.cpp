#include <cstring>
#include <iostream>
#include <typeinfo>
using namespace std;
template <typename T=int , int len=10 >
class Stack{
	T a[len];
	int cur;
public:
    const char* element()const{return typeid(T).name();}
	int max_size()const{return len;}
	Stack():cur(0){}
	void push(const T& d)throw(const char*) // 数据入栈成为栈顶
{
	if(full()) throw " already full ";
	a[cur++] = d;
}
	T pop()throw(const char*) //栈顶数据出栈
{
	if(empty()) throw" altreay empty ";
	return a[--cur];
}
	const T& top()const throw(const char*) // 取得栈顶数据
{
	if(empty()) throw " already empty ";
	return a[cur-1];
}
	bool empty()const // 是否为空栈
{
	return cur==0;
}
	bool full()const{return cur==5;} // 是否满栈 
	void clear(){cur=0;} //栈清空（复位）
	int size()const{return cur;}// 栈中数据个数
};
template < int len >
class Stack<const char*, len >{
	string a[len];
	int cur;
public:
    const char* element()const{return "const char*";}
	int max_size()const{return len;}
	Stack():cur(0){}
	void push(const char * d)throw(const char*) // 数据入栈成为栈顶
{
	if(full()) throw " already full ";
	a[cur++] = d;
}
	const char* pop()throw(const char*) //栈顶数据出栈
{
	if(empty()) throw" altreay empty ";
	return a[--cur].c_str();
}
	const char* top()const throw(const char*) // 取得栈顶数据
{
	if(empty()) throw " already empty ";
	return a[cur-1].c_str();
}
	bool empty()const // 是否为空栈
{
	return cur==0;
}
	bool full()const{return cur==len;} // 是否满栈 
	void clear(){cur=0;} //栈清空（复位）
	int size()const{return cur;}// 栈中数据个数
};

int main()
{	
	Stack<int> i;
	i.push(1);i.push(2);i.push(3);
	while(!i.empty()) cout << i.pop() << endl;
	char buf[100];
    Stack<const char*> s;
/*	s.push( "hello " ); s.push("world");*/
    for(;;){
		cin >> buf;
		if(strcmp(buf,"end")==0) break;
		s.push(buf);
	}
	cout << " ========================" << endl;
	while(!s.empty()) cout << s.pop() << endl;

	
}
