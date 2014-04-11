#include <algorithm>
using std::swap;
void sort(int* a, int n)//一个是出入数组的地址， 一个是对多少个数排序
{
	bool changed;
	do{
		changed = false;
		for(int i=1; i<n; i++)
		{
			if(a[i]<a[i-1]){
				swap(a[i],a[i-1]);
			changed = true;
			}//这一块显然是要加括号的， 如果没有加括号的话，因为是顺序执行所以changed始终会执行  就会用远都是true/
		}
	--n;
	}while(changed);
	

}
