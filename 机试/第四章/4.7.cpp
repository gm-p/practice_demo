#include <stdio.h>
int gcd(int a,int b)//�����Լ��
{
	return b!=0?gcd(b,a%b):a;
} 
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
		printf("%d\n",a*b/gcd(a,b));//��������˻������Լ������
	return 0; 
}
