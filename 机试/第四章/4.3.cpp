#include <stdio.h>
int main()
{
	long long a,b;//使用数据类型long long确保不会溢出
	int m;
	while(scanf("%d",&m)!=EOF)
	{
		if(m==0)
			break;//当m等于0时退出
		scanf("%lld%lld",&a,&b);//用%lld对long long变量赋值
		a=a+b;//计算a+b；
		int ans[50],size=0;//ans用来保存依次转换得到的各个数位数字的值，size表示其个数
		do//依次求的各个数位上的数字值
		{
			ans[size++]=a%m;//对m求摸
			a/=m;//除以m 
		} while(a!=0);//当a不为0时重复该过程
		for(int i=size-1;i>=0;i--)
			printf("%d",ans[i]);//输出，注意顺序为从高位到低位
		printf("\n");//输出换行 
	} 
	return 0;
}

