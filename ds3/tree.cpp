/*相对于上面的版本多了一个打印数的函数  用数状的形式 */
#include <iostream>
#include <iomanip>
using namespace std;
typedef char T;
class bst{
	struct Node{
		T data;
		Node* L;
		Node* R;
		Node(const T& d):data(d),L(),R(){}
		Node(const T& d, Node* l , Node* r):data(d),L(l),R(r){}
	};
	typedef Node* tree;
	Node* rp;
	int n;
public:
	bst():rp(),n(){}
	void update(const T& olddata, const T& newdata){
		if(remove(olddata))
			insert(newdata);
	}
	int size()const{return n;}
	void clear(){ clear(rp); n = 0;}
	~bst(){clear();}
	void insert(const T& d){
		insert(rp, new Node(d));
		++n;
	}
	tree& find(const T& d){
		return find(rp,d);//在一棵树上找d
	}
	void travel()const{
		travel(rp);
		cout << endl;
	}
	bool empty()const{
		return rp==NULL;//也可以判断n是否等于零来判断是否为empty
	}
	bool remove(const T& d){
		tree& t =find(d);
		if(t==NULL) return false;
		Node* p = t;
		if(t->L!=NULL)
			insert(t->R,t->L);
		t = t->R;
		delete p;
		--n;
		return true;
	}
	void insert(tree &t, Node* p){  //注意 t要引用
		if(t==NULL) t = p ;// 如果数为空的直接用将新的节点当作数根插入
		else if(p->data < t->data) 
			insert(t->L,p);
		else insert(t->R,p);
	}
	tree& find(tree& t, const T& d){//返回以d为根的子数的根指针
	if( t == NULL )
		return t;
	else if( d == t->data) return t;//find it
	else if( d < t->data) return find( t->L , d);
	else return find( t->R , d );//用传入的d的值来查找最后返回指针引用
	}
	void travel(tree t)const{//目前这个遍历的递归形式有点不清楚
		if(t != NULL){
			travel(t->L);
			cout << t->data << ' ' ;
			travel(t->R);
		}
		}
	void clear( tree& t ){
		if(t!=NULL){
			clear(t->L);
			clear(t->R);
			delete t; t=NULL;//清空后让根节点指向NULL要家引用才能让原来的根节点指向空的节点
		}
	}
	int high( tree t){
		if(t==NULL) return 0;
		int lh = high( t->L );
		int rh = high( t->R );
		return 1+(lh>rh?lh:rh);
	}
	const T& root()const{
		if(!rp) throw " empty ";
		return rp->data;//返回根节点的数据
	}
	void print(tree t, int space, char sign){
		if(t==NULL) return ;
		print(t->R,space+3,'/');
		cout << setw(space+1) << sign << t->data << endl;//打印根节点
		print(t->L, space+3,'\\');//后打右子树
	}
	void print(){
		print(rp , 0 , '*'); 
		cout << "==============" << endl;
		}
};
int main()
{
	bst b;
	b.insert('k');b.insert('s');b.insert('f');b.insert('t');
	b.insert('a');b.insert('m');b.insert('x');b.insert('e');
	b.insert('w');b.insert('b');b.insert('u');b.insert('j');
	b.print();
	b.remove('k');
	b.remove('m');b.remove('u');b.remove('j');
	b.print();
	b.update('b','k');b.update('k','b');b.update('x','*');
	b.print();
	while(!b.empty()) b.remove(b.root());
	cout << "size:" << b.size() << endl;
	b.print();


}
