#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include "print.h"

int main()
{
	int a[5] = {55, 44, 22, 11, 33};
	vector<int> vi(a, a+5);
	cout << vi.size() << endl;
//	sort(a, a+5);//sort the a[5] directly
	sort(vi.begin(), vi.end());//sort the data in vector
	vector<int>::iterator b = vi.begin();
	while(b!= vi.end()){
		cout << *b++ << ' ' ;
	}
		cout << endl;
		for(int i=0; i<5; i++)
			cout << a[i] << ' ';
			cout << endl;
	print(a, a+5);
	print(vi.begin(), vi.end());
	print(vi.rbegin(), vi.rend());
	b = vi.begin();
	vi.insert(++++b, 66);
	vi.insert(vi.begin(), 77);
	vi.insert(vi.end(), 88);
	print(vi.begin(), vi.end());
	cout << vi.size() << '/' << vi.max_size() << endl;
	vi.erase(------vi.end());
	print(vi.begin(), vi.end());
	vi.erase(++++vi.begin(), --vi.end());
	print(vi.begin(), vi.end());
	vector<int> v2(a, a+5);
	print(v2.begin(),v2.end());
	cout << "==============" << endl;
	vi.swap(v2);
	print(vi.begin(),vi.end());
	print(v2.begin(),v2.end());
	cout << "==============" << endl;
	swap(vi,v2);
	print(vi.begin(),vi.end());
	print(v2.begin(),v2.end());
	cout << "==============" << endl;
	vector<int> t = vi; vi = v2; v2 = t;
	print(vi.begin(),vi.end());
	print(v2.begin(),v2.end());
	vi.clear();
	cout << vi.size() << endl;
	print(vi.begin(), vi.end());
	vector<int> x;
	cout << " vector's present capacity:" << x.capacity() << endl;

}
