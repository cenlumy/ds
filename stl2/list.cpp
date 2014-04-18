#include <iostream>
using namespace std;
#include <list>
#include "print.h"
#include <cassert>


bool compare( int x, int y)
{
	x %= 3, y %= 3;
	return x < y;
}
int main()
{
	int a[10] = {3, 8, 8, 8, 5, 5, 1, 8, 8, 7};
	int b[6] = {9, 3, 5, 2, 7, 6};
	list<int> li(a, a+10), li1(b, b+6);
	print(li.begin(), li.end());
	li.unique();
    print(li.begin(), li.end());
	li.sort();
	print(li.begin(), li.end());
	li.unique();
	print(li.begin(), li.end());
	li.reverse();
	print(li.begin(), li.end());
	li.splice(li.begin(),li1);
	print(li.begin(), li.end());
//	assert(!li1.empty());
	assert(li1.empty());
	li.remove(5);
	print(li.begin(),li.end());
	li.sort();
	print(li.begin(), li.end());
	li.unique();
	li1.push_back(0);li1.push_back(4);li1.push_back(7);
	li1.push_back(5);li1.push_back(10);
	li1.sort();
	li.merge(li1);
	print(li.begin(), li.end());
	li1.assign(b, b+6);
	print(li1.begin(), li1.end());
	li1.sort();	
	print(li1.begin(), li1.end());
	li1.sort(greater<int>());
	cout << "=================="<< endl;
	print(li1.begin(), li1.end());
	li1.sort(compare);
	cout << "======================"<< endl;
	print(li1.begin(), li1.end());








}
