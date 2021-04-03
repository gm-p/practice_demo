#include <stdio.h>
int main()
{
	int a,b;//保存两个整数的变量
	while(scanf("%d%d",&a,&b)!=EOF)//输入两个整数
	{
		int buf1[20],buf2[20],size1=0,size2=0;//用buf1，buf2分别保存从两个整数中拆解出来的数位数字，其数量由size1，size2表示
		while(a!=0)//数位拆解，只要当a依然大于零就不断重复拆解过程
		{
			buf1[size1++]=a%10;//取得当前个位上的数字，将其保存
			a/=10;//将所有数位上的数字移动到高一位上 
		} 
		while(b!=0)//拆解第二个数字
		{
			buf2[size2++]=b%10;
			b/=10;
		}
		int ans=0;//计算答案
		for(int i=0;i<size1;i++)
			for(int j=0;j<size2;j++)
				ans+=buf1[i]*buf2[j]; //两两相乘后相加
		printf("%d\n",ans); 
	} 
	return 0;
}
