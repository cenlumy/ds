#include <algorithm>
using std::swap;
void sort(int* a, int n)
{
	//反复n-1次
	for(int i=0; i<n-1; i++){
		//第i次从i~n数据中找到最小的元素是谁
		int min = i;  //假设最小的为第i个
	    for(int j=i+1; j<n; j++)
			if(a[j] < a[min])
				min = j;//里面的这个for循环用于每次找到最小的那个数
	//把它跟第i个元素交换
	swap(a[min],a[i]);//将找到的最小的和a[i]交换就行了。 
	}
}/*
#include <algorithm>
using std::swap;
void sort(int* a, int n)
{
	for(int i=1; i<n; i++){
		int min = i;  //假设最小的为第i个
	    for(int j=i+1; j<n; j++)
			if(a[j] < a[min])
				min = j;//里面的这个for循环用于每次找到最小的那个数
	//把它跟第i个元素交换
	swap(a[min],a[i-1]);//将找到的最小的和a[i]交换就行了。 
	}
}
*/
