#include<stdio.h>
int gcd(int a,int b)
{
	while(b!=0)//ֻҪb��Ϊ0��һֱ�����ù���
	{
		int t=a%b;
		a=b;//ʹa���b 
		b=t;//ʹb���a%b 
	} 
	return a;//��bΪ0ʱ��a�������� 
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
		printf("%d\n",gcd(a,b));
	return 0;
} 
