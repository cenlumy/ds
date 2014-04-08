#include <iostream>
using namespace std;
#include <string>
typedef std::string T;
class Stack{
	T a[5];
	int cur;
public:
	Stack():cur(0){}
	void push(const T& d)throw(const char*)//数据入栈成为栈顶
	T pop()throw(const char*);//栈顶出栈，下一个数据成为栈顶
	const T& top() const throw(const char*)//取得栈顶数据
	bool empty()const{return cur==0;}//是否空栈
