#include <iostream>
using namespace std;
#include <string>
typedef std::string T;
class Stack{
	T a[5];
	int cur;
public:
	Stack():cur(0){}
	void push(const T& d)throw(const char*); // 数据入栈成为栈顶
	T pop()throw(const char*); //栈顶数据出栈
	const T& top()const throw(const char*); // 取得栈顶数据
	bool empty()const; // 是否为空栈
	bool full()const{return cur==5;} // 是否满栈 
	void clear(){cur=0;} //栈清空（复位）
	int size()const{return cur;}// 栈中数据个数
};
void Stack::push(const T& d)throw(const char*){
	if(full()) throw " already full ";
	a[cur++] = d;
}
T Stack::pop() throw(const char*){
	if(empty()) throw" altreay empty ";
	return a[--cur];
}
const T& Stack::top()const throw(const char*){
	if(empty()) throw " already empty ";
	return a[cur-1];
}
bool Stack::empty()const{
	return cur==0;
}

int main()
{	
	Stack s;
	try{
	s.push("lihuan");
	s.push("lumin");
	s.push("huiya");
	s.push("wangfeng");
	s.push("chencaiweng");
	s.push("how are you");
	}
	catch(const char* e){
		cout << " exception :" << e << endl;
	}
	while(!s.empty()){
		cout << s.pop() << endl;
	}
}
