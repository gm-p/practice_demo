//华为编程题：删数
/* 
有一个数组a[N]顺序存放0-N，
要求没隔两个数删掉一个数，
到末尾时循环至开头继续进行，
求最后一个被删掉的数的原始下标位置。
以8个数(N=7)为例:｛0，1，2，3，4，5，6，7｝，
0->1->2(删除)->3->4->5(删除)->6->7->0(删除),
如此循环直到最后一个数被删除。 
*/

#include <iostream>
using namespace std;

int main()
{
	int a[1001];
	int index=0, count=0;
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		a[i] = 1;
	for(int i=0; count<n-1; i++)
	{
		if(a[i%n] == 0)
			continue;
		
		index++;
		if(index == 3)
		{
			a[i%n] = 0;
			index = 0;
			count++;
		}
	}
	for(int i=0; i<n; i++)
		if(a[i])
			cout<<i<<endl;
	return 0;
}
