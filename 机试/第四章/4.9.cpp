#include <stdio.h>
int prime[10000];//保存筛得的素数
int primeSize;//保存的素数的个数
bool mark[10001];//若mark[x]为true，则表示该数x已被标记成非素数
void init()//素数筛选
{
	for(int i=1;i<=10000;i++)
		mark[i]=false;//初始化，所有数字均没被标记
	primeSize=0;//得到的素数个数为0
	for(int i=2;i<=10000;i++)//依次遍历2到10000所有数字
	{
		if(mark[i]==true)
			continue;//若该数字已经被标记，则跳过
		prime[primeSize++]=i; 
		for(int j=i*i;j<=10000;j+=i)//并将该数的所有倍数均标记成非素数
			mark[j]=true; 
	}
} 
int main()
{
	init();//在程序一开始首先取到2到10000中所有素数
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		bool isOutput=false;//表示是否输出了符合条件的数字
		for(int i=0;i<primeSize;i++)//依次遍历得到的所有素数
		  if(prime[i]<n&&prime[i]%10==1)//测试当前素数是否符合条件
		  {
		  	if(isOutput==false)//若当前输出为第一个输出的数字，则标记已经输出了符合条件的数字，且该数字前不输出空格
			  {
			  	isOutput=true;
			  	printf("%d",prime[i]);
			  } 
			else
				printf(" %d",prime[i]);
		  }
		  if(isOutput==false)//若始终不存在符合条件的数字
		  	printf("-1\n");//输出-1并换行
		  else
		  	printf("\n");//换行 
	} 
	return 0;
}
