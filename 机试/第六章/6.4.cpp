#include <stdio.h>
#include <string.h>
long long F(int num)//�ݹ麯��������ֵ�ϴ�ʹ��long long����
{
	if(num==1)
		return 2;//������Ϊ1ʱֱ�ӷ���2
	else
		return 3*F(num-1)+2;//����ݹ����F(num-1) 
} 
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)//����
	{
		printf("%lld\n",F(n));//����� 
	} 
	return 0;
}
