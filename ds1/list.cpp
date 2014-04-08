#include <iostream>
using namespace std;
typedef int T;
class List{
	struct Node{
		T data;
		Node* next;
		Node(const T& d):data(d),next(NULL){}
	};
	int len;
	Node* head;
public:
	List():head(NULL),len(0){}
	void push_front(const T& d){
		insert(d,0);
	/*	Node* p = new Node(d);
		p->next = head;
		head = p;//让head 指向p*/
	}
	List& push_back(const T& d){//尾插
		insert( d , size());
		return *this;
	}
	int size() const{
		return len;
	/*	int cnt=0;
		Node* p = head;
		while(p!=NULL){
			++cnt;
			p = p->next;
		}
		return cnt;*/
	}
	Node*& getptr( int pos ){
		if(pos < 0||pos> size()) pos=0;
		if( pos==0) return head;
		Node* p = head;
		for( int i = 1; i < pos ; i++)
			p = p->next;
		return (*p).next;//(*p).next;
	}
	void insert(const T& d, int pos){//在任意位置插入
		Node*& pn = getptr(pos);
		Node* p = new Node(d);
		p->next = pn;
		pn = p;  //pn  指向新节点的地址
		++len;
	}
	void travel()const{//遍历
		Node* p = head;
		while(p!=NULL){
			cout << p->data << " " ;
			p = p->next;
	}
	cout << endl;
	}
	void clear(){ // 清空这个链表 
	while(head!=NULL){
		Node* p = head->next;
		delete head;
		head = p;
	}
	len = 0;
	}
	~List(){
		clear();
	}
	void erase(int pos){
		if(pos<0 || pos>=size()) return;
		Node* & pn = getptr(pos);
		Node* p = pn;
		pn = pn->next;
		delete p;
		--len;
	}
	void remove(const T& d){
		int pos;
	while((pos=find(d))!=-1)//	while((pos=find(d))=!-1)
			erase(pos);
	}
	int find(const T& d)const{
		int pos = 0;
		Node* p = head;
		while(p){
			if(p->data==d) return pos;
			p = p->next; ++pos;
		}
		return -1;
	}
	void set(int pos, const T& d){
		if(pos<0 || pos>size()) return;
		getptr(pos)->data = d;
	}
	bool empty()const{ return head == NULL;}
	T front()const{
		if(empty())
			throw " empty " ; 
		return head->data;
	}
	T back()const{
		if(empty()) 
			throw " empty ";
		Node* p = head;
		while(p->next!=NULL)//当p等于空的时候退出
			p = p->next; //用于使p指向最后的一个节点；
		return p->data;
	}

};
int main(){
	List l;
	l.push_front(5);
	l.push_front(8);
	l.push_front(20);
	l.insert(9,2);
	l.insert(6,100);
	l.insert(7,-10);
	l.insert(1,2);
	l.push_back(10).push_back(15).travel();
	l.erase(0);
	l.erase(l.size()-1);
	l.erase(2);
	l.travel();
	l.push_back(6);
	l.insert(6,3);
	l.travel();
	l.remove(6);
	l.travel();
	l.set(0,666);
	l.set(4,789);
	l.set(l.find(9),123);//此处的9返回的是pos 刚好可以
	l.travel();
	l.set(1,777);
    l.travel();
	cout << l.front() << "...." << l.back() <<' '<< l.size()
	<<"个" << endl;
    while(!l.empty())
		l.erase(0);
	cout << " size : " << l.size() << endl;

	return 0;
}
