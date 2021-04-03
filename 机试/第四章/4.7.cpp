#include <stdio.h>
int gcd(int a,int b)//求最大公约数
{
	return b!=0?gcd(b,a%b):a;
} 
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
		printf("%d\n",a*b/gcd(a,b));//输出两数乘积与最大公约数的商
	return 0; 
}
