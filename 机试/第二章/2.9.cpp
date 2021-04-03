#include <stdio.h>
#define OFFSET 500000 //偏移量，用于补偿实际数字与数组下标之间偏移
int Hash[1000001];//Hash数组，记录每个数字是否出现，不出现为0，出现后被标记成1
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=-500000;i<=500000;i++)
		  Hash[i+OFFSET]=0;//初始化，将每个数字都标记为未出现
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			Hash[x+OFFSET]=1;//凡是出现过的数字，该数组元素均设置成1 
		} 
		for(int i=500000;i>=-500000;i--)//输出前m个数
		{
			if(Hash[i+OFFSET]==1)//若该数字在输入中出现 
			{
				printf("%d",i);//输出该数字 
				m--;//输出一个数字后，m减一，直至m变为0
				if(m!=0)
				  printf(" ");//注意格式，若m个数未被输出完毕，在输出的数字后紧跟一个空格
				else
				{
					printf("\n");//若m个数字已经被输出完毕，则在输出的数字后面紧跟一个换行，并跳出循环
					break; 
				} 
			}
		} 
	}
	return 0;
} 
