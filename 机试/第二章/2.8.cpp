#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)//�����ж����Ӷ�n�Ƿ����������ж�
	{
		int Hash[101]={0};//����һ����ʼΪ0��Hash����������¼���ַ������ֵĴ���
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			Hash[x]++;//ͳ�Ʒ������ִ��� 
		} 
		int x;
		scanf("%d",&x);
		printf("%d\n",Hash[x]);//�õ���Ҫ��ѯ��Ŀ�������ֻ��򵥵Ĳ�ѯ����ͳ�Ƶ��������� 
	} 
	return 0;
}

