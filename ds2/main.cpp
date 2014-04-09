#include <iostream>
typedef int T;
using namespace std;
#include "list01.h"

int main()
{
	List l;
	l.push_back(1).push_back(2).push_front(3);
	l.travel();
}
