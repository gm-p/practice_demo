#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int x=0;x<=100;x++)//枚举x的值
		{
			for(int y=0;y<=100-x;y++)//枚举y的值，注意它们的和不可能超过100
			{
				int z=100-x-y;//计算z的值
				if(x*5*3+y*3*3+z<=n*3)//考虑到一只小小鸡的价格为1/3，为避免除法带来的精度损失，这里采用了对不等式两端所有数字都乘3的操作，这也是避免除法的常用技巧
					printf("x=%d,y=%d,z=%d\n",x,y,z);//输出 
			} 
		} 
	} 
	return 0; 
}
