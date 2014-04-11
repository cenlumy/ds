#include <iostream>
#include <algorithm>
using namespace std;
class Person{
	string name;
	int age;
	string addr;
public:
	Person(const char* n, int  a, const char* ad)
	:name(n),age(a),addr(ad){}
	friend bool operator<(const Person& a, const Person& b){
		return a.name < b.name;
	}
	friend bool operator==(const Person& a, const Person& b){
		return a.name == b.name;
	}
	friend ostream& operator<<(ostream& o, const Person& a){
		o << a.name << ':' << a.age << ',' << a.addr;
	}
	Person* binarysearch(Person* a, int n, const string& name)
	{
		int b = 0 , e = n-1;
		Person t(name.c_str(),0,"");
		while(b<=e){
			int mid = (b+e)/2;
			if(a[mid]==t) return a+mid;
			if(t<a[mid])  e = mid-1;
			else b = mid + 1;
		}
		return NULL;//要忘记诶这个NULL
	}
/*	Person* binarysearch(Person* a, int n , const string& name)
	{
		if(n<=0) return NULL;
		int mid = n/2;
		Person t(name.c_str(),0,"");
		if(a[mid] == t) return a+mid;
		if(t < a[mid]) return binarysearch(a,mid,name);
		return binarysearch(a+mid+1,n-mid-1,name);
	}*///一般我们把这个函数写在外面不然的还要通过调用对象的成员函数来调用他
};
int main()
{
	Person a[5]={
		Person("chenlumin",20,"xiamen"),
		Person("lihuan", 19, "zaoqing"),
		Person("huiya",21,"xiamen"),
		Person("chencaiweng",44,"xiamen"),
		Person("wangfeng",45,"xiamen")
	};
// 因为没有定义无参构造函数， 所以定义5个person 的话要同时初始化。
	for(int i=0; i<5; i++)
		for(int j=i+1; j<5; j++)
			if(a[j]<a[i])
				swap(a[j],a[i]);
	for(int i=0; i<5; i++)
		cout << a[i] << endl;
	string name;
	cout << "please enter a name:" ;
	cin >> name;
	/*int  n = binarysearch(a,5,name)
	cout << a[n] << endl;*/ //如果是返回下标的话  
	Person *p =a[1].binarysearch(a,5,name);/*
	cout << *p << endl;//这样的可能会出现段错误，当输入的名字不匹配的时候改进的方法如下*/
	if(p!=NULL) 
		cout << *p << endl;
	else cout << " sorry I can't find it ." << endl;


}
