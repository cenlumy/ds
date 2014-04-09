	#include <iostream>
	using namespace std;
    typedef int T;
	#include "list01.h"
	void List::push_front(const T& d){
		insert(d,0);
	}
	List& List::push_back(const T& d){//尾插
		insert( d , size());
		return *this;
	}
	int List::size() const{
		return len;
	}
   	List::Node*& List::getptr( int pos ){
		if(pos < 0||pos> size()) pos=0;
		if( pos==0) return head;
		Node* p = head;
		for( int i = 1; i < pos ; i++)
			p = p->next;
		return (*p).next;//(*p).next;
	}
	void List::insert(const T& d, int pos){//在任意位置插入
		Node*& pn = getptr(pos);
		Node* p = new Node(d);
		p->next = pn;
		pn = p;  //pn  指向新节点的地址
		++len;
	}
	void List::travel()const{//遍历
		Node* p = head;
		while(p!=NULL){
			cout << p->data << " " ;
			p = p->next;
	}
	cout << endl;
	}
	void List::clear(){ // 清空这个链表 
	while(head!=NULL){
		Node* p = head->next;
		delete head;
		head = p;
	}
	len = 0;
	}
	List::~List(){
		clear();
	}
	void List::erase(int pos){
		if(pos<0 || pos>=size()) return;
		Node* & pn = getptr(pos);
		Node* p = pn;
		pn = pn->next;
		delete p;
		--len;
	}
	void List::remove(const T& d){
		int pos;
	while((pos=find(d))!=-1)//	while((pos=find(d))=!-1)
			erase(pos);
	}
	int List::find(const T& d)const{
		int pos = 0;
		Node* p = head;
		while(p){
			if(p->data==d) return pos;
			p = p->next; ++pos;
		}
		return -1;
	}
	void List::set(int pos, const T& d){
		if(pos<0 || pos>size()) return;
		getptr(pos)->data = d;
	}
	bool List::empty()const{ return head == NULL;}
	const T& List::front()const{
		if(empty())
			throw " empty " ; 
		return head->data;
	}
	const T& List::back()const{
		if(empty()) 
			throw " empty ";
		Node* p = head;
		while(p->next!=NULL)//当p等于空的时候退出
			p = p->next; //用于使p指向最后的一个节点；
		return p->data;
	}



