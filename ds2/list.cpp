#include <iostream>
using namespace std;
typedef int T;
#include "list.h"
void List::push_front(const T& d){//前插
	insert(d,0);
	}
List& ::push_back(const T& d){//尾插
	insert(d, size());
	return *this;
}
int List::size()const{
	return len;
}
List::Node*& List::getptr(int pos){//找链表中指向指定位置的指针
	if(pos<0||pos>size()) pos=0;
	if(pos==0) return head;
	Node* p = head;
	for(int i=1; i<pos; i++)
		p = p->next;
		return (*p).next;
}
