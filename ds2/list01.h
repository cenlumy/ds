#ifndef LIST_H
#define LIST_H 1
class List{
	struct Node{
		T data;
		Node* next;
		Node* prev;
		Node(const T& d=T()):data(d),next(0){}
	};
	int len;
	Node* head;
public:
	List():head(0),len(0){}
	void push_front(const T& d);
	List& push_back(const T& d);//尾插
	int size() const;
	Node*& getptr( int pos );
	void insert(const T& d, int pos);//在任意位置插入
	void travel()const;//遍历
	void clear(); // 清空这个链表 
	~List();
	void erase(int pos);
	void remove(const T& d);
	int find(const T& d)const;
	void set(int pos, const T& d);
	bool empty()const;
	const T& front()const;
    const T& back()const;
};
#endif
