#include <stdio.h>
#include <string.h>
long long F(int num)//递归函数，返回值较大使用long long类型
{
	if(num==1)
		return 2;//当参数为1时直接返回2
	else
		return 3*F(num-1)+2;//否则递归调用F(num-1) 
} 
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)//输入
	{
		printf("%lld\n",F(n));//输出答案 
	} 
	return 0;
}
