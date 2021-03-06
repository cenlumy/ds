#include <iostream>
using namespace std;
typedef int T;
struct Node{
	T data;
	Node* next;
	Node(const T& d):data(d),next(NULL){}
	operator T(){return data;}
};
void showlist(Node* head)
{
	Node* p = head;
	while(p!=NULL){
		cout << *p << ' ';
		p = (*p).next;
	}
	cout << endl;
}

int main()
{
	Node a(10),b(20),c(30),d(40),e(50),f(60) ;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	showlist(&a);
	Node* & p = b.next;
	e.next = p;// b.next;
	p = &e;//b.next = &e;
	showlist(&a);
	Node*& q = a.next;
	f.next = q;//q==a.next==&b
	q = &f;//a.next = &f
	showlist(&a);
	Node* k = new Node(80);
	Node*& r = c.next;
	k->next = r;
	r = k;
	showlist(&a);
	delete k;
	

}
