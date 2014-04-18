#ifndef PRINT_H
#define PRINT_H 1
template <typename T>
void print( T b, T e,char c = ' ')
{
	while(b!=e){
		cout << *b++ << c;
}
	cout << endl;
}
#endif
