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

int main()
{	
	Stack<double, 30> d;
    Stack<char , 20> s;
	Stack<float> f;
	Stack<> a;
	s.push('+');
	s.push('-');
	s.push('*');
	s.push('/');
//	cout << typeid(s).name() << endl;
//	cout << typeid(d).name() << endl;
//	while(!s.empty())
//		cout << s.pop() << endl;
//	d.push(100);
//	d.push(60);
//	d.push(234.34);d.push(324.234);
//	while(!d.empty())
//		cout << d.pop() << endl;
	cout << d.size() << '/' << d.max_size() << ':' << d.element() << endl;
	cout << s.size() << '/' << s.max_size() << ':' << s.element() << endl;
	cout << f.size() << '/' << f.max_size() << ':' << f.element() << endl;
	cout << a.size() << '/' << a.max_size() << ':' << a.element() << endl;

	
}
