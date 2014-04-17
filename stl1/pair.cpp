#include<iostream>
#include <cstdlib>
using namespace std;
template <typename To, typename From>
To convertto(From v)
{
	return To(v);
}
template <typename To>
To convertto(const char* str)
{
	return To(atof(str));
}
template <typename T, typename U>
struct Pair{
	T first;
	U second;
	Pair():first(),second(){}
	Pair(const T& a, const U& b):first(a),second(b){}
	template <typename X ,typename Y>
	Pair& operator=(const Pair<X,Y>& p){//用模板重载类型的赋值运算符号
		first = convertto<T>(p.first);
		second = convertto<U>(p.second);
		return *this;
	}
};
template <typename T, typename U>
ostream& operator<<(ostream& o,const Pair<T,U>& p)
{
	return o << p.first << ':' << p.second;
}
template <typename T, typename U>
Pair<T,U> mp(T f,U s)
{
	return Pair<T,U> (f,s);}

int main()
{
	cout << Pair<const char* ,int>("chenlumin",21) << endl;
	cout << Pair<int,double>(20,6789.5) << endl;
	cout << mp("chenlumin" , 18)  << endl;
	cout << mp(20 , 6789.9) << endl;
	Pair<int,double> a(123,45.6);
	cout << "a=" << a << endl;
	Pair<const char* ,const char* > b("78","90.5");
	a = b;
	cout << "a=" << a << endl;

}
