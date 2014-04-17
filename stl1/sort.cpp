#include <algorithm>
#include <cstring>
using  namespace std;
#include <iostream>
using std::swap;
template <typename T >//指针数组排序的偏特化版本
void sort(T* a[] , int n)
{// 选择排序
	for( int i=0; i<n-1; i++){
		int min = i;
		for( int j = i+1; j < n; j++)
			if(*a[j] < *a[min])
				min = j;
			swap(a[min],a[i]);
	}
}
template < typename T >
void sort(T* a , int n)//equal to void sort( T a[], int n) T是哪种类型的话我们从数组中取出来的就是那种类型的元素。
{// 选择排序
	for( int i=0; i<n-1; i++){
		int min = i;
		for( int j = i+1; j < n; j++)
			if(a[j] < a[min])
				min = j;
			swap(a[min],a[i]);
	}
}
template <>//特化不需要传参数
void sort(const char* a[] , int n)
{// 选择排序
	for( int i=0; i<n-1; i++){
		int min = i;
		for( int j = i+1; j < n; j++)
			if(strcmp(a[j],a[min])<0)
				min = j;
			swap(a[min],a[i]);
	}
}
struct Date{
	int y, m, d;
	//Date(int y, int m, int d,):y(y),m(m),d(d);
};
ostream& operator<<(ostream& o , const Date& d)
{
   return	o << d.y << '-' << d.m << '-' << d.d ;
}
bool operator<(const Date& a, const Date& b){
	if(a.y<b.y||a.y==b.y&&(a.m<b.m||a.m==b.m&&a.d<b.d))
		return true;
	else 
		return false;
	}
template < class T > 
void show( T a[] , int n)
{
	for( int i=0 ; i<n ; i++)
		cout << a[i] << ' ' ;
		cout << endl;

}
/*template < typename T >
void show(T& t)
{
	int n = sizeof(t)/sizeof(t[0]);
	for( int i=0; i<n ; i++)
		cout << t[i] << ' ' ;
		cout << endl;
}*/
template < typename T ,  int N>
void show(T(&t)[N])//此是为了实现不让不是数组类型的去调用这个函数的。
{
	for(int i=0 ; i<N ; i++)
		cout << t[i] << ' ' ;
		cout << endl;
}
template < typename T ,  int N>
void show(T*(&t)[N])//此是为了实现不让不是数组类型的去调用这个函数的。
{
	for(int i=0 ; i<N ; i++)
		cout << *t[i] << ' ' ;
		cout << endl;
}
template <typename T>
void show( T data )
{
	cout << data << endl;
}	
int main()
{
	double m = 123.3;
	show(m);
	int a[5]={6,1,9,2,7};
	double d[4] = { 3.3,5.5,1.2,5.7 };
	Date x[3]={{2014,4,13},{2004,3,3},{2099,9,9}};
	//sort(reinter_cast<int*>(d),3);
	sort(a , 5);//a==> int*  
	sort(d , 4);
	sort(x , 3);
	show(a , 5);
	show(d , 4);
	show(x , 3);
	show(a);show(d);show(x);
	const char* s[3]={"wangfeng","chenhuiya", "chencaiweng"};
	sort(s,3);
	show(s);
	int* ap[4]={new int(50) ,new int(2), new int(9), new int(8)};
	double* bp[3]={new double(3.3),new double(5.5), new double(2.2)};
	sort(ap,4);sort(bp,3);
	show(ap);show(bp);
	}

