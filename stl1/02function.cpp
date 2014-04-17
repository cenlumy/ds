#include <iostream>
#include <cstring>
using namespace std;
template <typename T>
const T& Min(const T& a, const T& b)//&避免复制
{
	cout << 'a' ;return a<b?a:b;
}
template <typename T>
 T& Min( T& a,  T& b)//&避免复制
{
	cout << 'b' ;return a<b?a:b;
}
template <typename T, typename U>
T Min(const T& a, const U& b)
{
	cout << 'C' ; return a<b?a:T(b);//因为冒号左右的类型要一致，所以我们将T转换成和t相同的类型 用的是强制类型转换也可以用static_cast之类的
}
const char* Min(const char* a, const char* b)
{
	cout << 'd' ; return strcmp(a,b)<0?a:b;
}
template <typename T>
T Min(const T&a , char b)//偏特化  固定一个参赛类型 其他的不固定
{
	cout << 'e' ; return (a<b?a:T(b));
}
template<>
double& Min(double& a, double& b)//全特化模板里面没有未定类型
{
	cout << 'F' ; return a<b?a:b;
}
int main()
{
	int m=20, n = 10;
	double x=1.1 , y = 2.3;
	cout << Min(x,y) << endl;
	cout << Min(m,n) << endl;
	cout << (30,40) << endl;
	cout << Min(5.9,6) << endl;
	cout << Min("hello", "world") << endl;
	cout << Min<>("hello","world") << endl;
	cout << Min(123,'x') << endl;

}
