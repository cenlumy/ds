#include <algorithm>
using std::swap;
void sort(int* a, int  n)
{
	if(n<=1) return;
	if(n==2){
		if(a[1]<a[0]) swap(a[1],a[0]);
		return ;
	}//当只有一个或者两个的时候直接进行处理
	swap(a[n/2],a[0]);//先把a[0]和分解值进行交换
	int jie = a[0]; 
	int* L = a+1;
	int* R = a+n-1;//等同与 int* R = &a[n-1]
	while(L<R){
		while(L<R&&*L<jie) ++L;//备注如果没有加L<R的话那么就会越界
		while(a<R&&!(*R<jie)) --R;//不小于分界值就是大于写成这样估计是因为只是重载了小于符号把，a和R比的原因是因为a和R有交错刚好可以防止越界
			if(L<R) swap(*L,*R);
	}
	if(*R<jie) swap(*R,a[0]);//刚好等于的花就不用了显然界只可能是等于或者是小于
	sort(a,R-a);//地址相减得到的是元素的个数
	sort(R+1,n-1-(R-a));//分界值是R从第R+1开始总共n个元素减去分界值一个减去左边的R-a个然后就是右边的个数了。 后面这两条语句是递归的。
}
