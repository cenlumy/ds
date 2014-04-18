#include <iostream>
#include <string>
#include <deque>
using namespace std;
#include "print.h"

int main()
{
	deque<string> ds;
//	deque< vector<int> >; between the > and > is space 
	ds.push_back("chenlumin");
	ds.push_back("are");
	ds.push_back("you");
	ds.push_back("kidding");
	ds.push_back("me");
	print(ds.begin(), ds.end(),',');
	ds.insert(++++ds.begin(),2,"hah");
	print(ds.begin(),ds.end());
	string s[3] ={"chenhuiya","chencaiweng", "wangfeng"};
	ds.insert(----ds.end(),s,s+3);
	print(ds.begin(), ds.end());
	ds.pop_back(); 
	ds.pop_back();
	print(ds.begin(),ds.end(),',');
	ds.resize(12,"lumin");
 //	print(ds.begin(),ds.end());
	ds.assign(5,"chenlumin");
	print(ds.begin(),ds.end());
	ds.clear();
	ds.front() = "chenhuiya";
	ds.back() = "wangfeng";
	print(ds.begin(), ds.end());



    

}
