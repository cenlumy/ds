#include <iostream>
using namespace std;
#include <algorithm>
#include <string>

template <typename T>
void print(T b, T e)
{
	while(b!=e)
		cout << *b++ << ' ';
	cout << endl;
}
class Person{
	string name;
	int age;
public:
	Person(const char* name, const int age):name(name),age(age){}
	friend ostream& operator<<(ostream& o, const Person& b){
		return o << b.name << ':' << b.age ;
	}
	friend bool operator<(const Person& a, const Person b)
	{
		return a.age<b.age;//compare  Person by the age
	}
};

int main()
{
	int a[6] = {8, 1, 6, 3, 2, 9};
	double b[4] = {2.2, 3.3, 1.1, 4.2};
	string c[5]={"hello", "everyone", "luck", "with", "you"};
	Person d[3] ={Person("chenlumin",22), Person("huiya",24), Person("wengfeng",43)};
	sort(a, a+6);
	sort(b, b+4);
	sort(c, c+5);
	sort(d, d+3);
	print(a, a+6);
	print(b, b+4);
	print(c, c+5);
	print(d, d+3);
}
