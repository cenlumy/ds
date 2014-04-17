#include <typeinfo>
#include <iostream>
using namespace std;
template < int n >
class Fact{
public:
	enum{val = Fact<n-1>::val*n};
};
template <>
class Fact<0>{//针对于n=0时的特化
public:
	enum {val = 1};
};
template < typename T > 
class Type{
public: 
	static string name(){ return typeid(T).name();}
};
template <>
class Type<char>{
public:
	static string name(){ return "char " ;}
};
template <>
class Type<double>{
public:
	static string name(){ return "double " ;}
};
template <>
class Type<int>{
public:
	static string name(){ return "int " ;}
};
template <>
class Type<bool>{
public:
	static string name(){ return "bool" ;}
};
template <typename T>
class Type<T*>{
public:
	static string name(){ return Type<T>::name()+ "pointer";}
};
int main()
{
	cout << Fact<5>::val << endl;
	cout << Type<double>::name() << endl;
	cout << Type<char>::name() << endl;
	cout << Type<double>::name() << endl;
	cout << Type<int*>::name() << endl;
	cout << Type<double*>::name() << endl;
	cout << Type<bool**>::name() << endl;
}

