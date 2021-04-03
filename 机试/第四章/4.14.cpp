#include <stdio.h>
#include <string.h>
struct bigInteger
{
	int digit[1000];
	int size;
	void init()//初始化
	{
		for(int i=0;i<1000;i++)
			digit[i]=0;
		size=0;
	} 
	void set(int x)//用一个小整数设置高精度整数
	{
		init();
		do//对小整数4位为一个单位分解依次存入digit当中
		{
			digit[size++]=x%10000;
			x/=10000;
		}while(x!=0);
	} 
	void output()//输出
	{
		for(int i=size-1;i>=0;i--)
		{
			if(i!=size-1)
				printf("%04d",digit[i]);
			else
				printf("%d",digit[i]);
		}
		printf("\n");
	} 
	bigInteger operator*(int x)const//乘法运算符
	{
		bigInteger ret;//将要返回的高精度整数
		ret.init();//初始化
		int carry=0;//进位初始值为0
		for(int i=0;i<size;i++)
		{
			int tmp=x*digit[i]+carry;//用小整数x乘以当前数字并加上来自低位的进位
			carry=tmp/10000;//计算进位
			ret.digit[ret.size++]=tmp;//保存该位数字 
		} 
		if(carry!=0)//若最高位有进位
			ret.digit[ret.size++]=carry;//保存该进位 
		return ret;
	} 
}a;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		a.init();//初始化a
		a.set(1);//a初始值为1
		for(int i=1;i<=n;i++)
			a=a*i;//依次乘上每一个整数
		 a.output();//输出a 
	}
	return 0;
}
