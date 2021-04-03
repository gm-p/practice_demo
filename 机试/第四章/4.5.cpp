#include <stdio.h>
int gcd(int a,int b)
{
	if(b==0)
		return a;//若b为零则最大公约数为a
	else
		return gcd(b,a%b);//否则，则改为求b与a%b的最大公约数 
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)//输入两个正整数
		printf("%d\n",gcd(a,b));//输出所求的最大公约数
	return 0; 
}
