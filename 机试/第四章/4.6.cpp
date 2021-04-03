#include<stdio.h>
int gcd(int a,int b)
{
	while(b!=0)//只要b不为0则一直持续该过程
	{
		int t=a%b;
		a=b;//使a变成b 
		b=t;//使b变成a%b 
	} 
	return a;//当b为0时，a既是所求 
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
		printf("%d\n",gcd(a,b));
	return 0;
} 
