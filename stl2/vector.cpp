#include <iostream>
using namespace std;
#include <vector>
#include "print.h"
#include <exception>
#include <typeinfo>
int main()
{
	vector<double> vd, vv;
	for(int i=0; i<9; i++){
		vd.push_back(i+0.1);
		cout << &*vd.begin() << ':';
		cout << vd.size() << '/' << vd.capacity() << endl;
	}
	cout << "======================" <<endl;
	vv.reserve(9);
	for(int i=0; i<9; i++){
		vv.push_back(i+0.1);
		cout << vv.size() << '/' << vv.capacity() << endl;
	}
	vd[3] =123.34;
	vv.at(5) = 89.3;
	for(int i=0; i<=vd.size(); i++)
		cout <<vd[i] << ' ';
		cout << endl;
	try{
	for(int i=0; i<=vd.size(); i++)
		cout <<vv.at(i) << ' ';
		cout << endl;
	}catch(exception& e){
		cout << "exception:" << e.what() << endl;
		cout << "type:" << typeid(e).name() << endl;
	}
	int m =3, n = 5;
	void print(const vector<vector<int> >& e);
	vector< vector<int> > vvi(m, vector<int>(n));//m line and n row .
	print(vvi);
	vvi.resize(m+3);
	vvi[3].assign(9,1);
	vvi[5].assign(4, 5);
	print(vvi);
}
void print(const vector<vector<int> >& e)
{
	for( int i = 0; i<e.size(); i++){
		for(int j = 0; j < e[i].size(); j++)
			cout << e[i][j]<<' ';
	cout << endl;
	}
}
template < typename T >
void show(T a[], int n);// the array must followed with the n to express how many element the a[] have
template < typename T>
void show(const vector<T>& v);//dont need the n like the array
