//��Ϊ����⣺ɾ��
/* 
��һ������a[N]˳����0-N��
Ҫ��û��������ɾ��һ������
��ĩβʱѭ������ͷ�������У�
�����һ����ɾ��������ԭʼ�±�λ�á�
��8����(N=7)Ϊ��:��0��1��2��3��4��5��6��7����
0->1->2(ɾ��)->3->4->5(ɾ��)->6->7->0(ɾ��),
���ѭ��ֱ�����һ������ɾ���� 
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
