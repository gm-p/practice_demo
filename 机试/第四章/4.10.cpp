#include <stdio.h>
bool mark[100001];
int prime[100001];
int primeSize;
void init()
{
	primeSize=0;
	for(int i=2;i<=100000;i++)
	{
		if(mark[i]==true)
			continue;
		prime[primeSize++]=i;
		if(i>=1000)
			continue;
		for(int j=i*i;j<=100000;j+=i)
			mark[j]=true;
	}
}//以上与上例一致，用素数筛法筛选出2到100000内的所有素数
int main()
{
	init();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int ansPrime[30];//按顺序保存分解出的素因素
		int ansSize=0;//分解出素因素的个数
		int ansNum[30];//保存分解出的素因素对应的幂指数
		for(int i=0;i<primeSize;i++) //依次测试每一个素数
		{
			if(n%prime[i]==0)//若该素数能整除被分解数
			{
				ansPrime[ansSize]=prime[i];//则该素数为素因素
				ansNum[ansSize]=0;//初始化幂指数为0
				while(n%prime[i]==0)//从被测试数中将该素数分解出来，并统计其幂指数 
				{
					ansNum[ansSize]++;
					n/=prime[i];
				} 
				ansSize++;//素因素个数增加
				if(n==1)
					break;//若已被分解成1，则分解提前终止 
			} 
		} 
		if(n!=1)//若测试完2到100000内所有素因素，n仍未被分解至1，则剩余的因素一定是n一个大于100000的素因素
		{
			ansPrime[ansSize]=n;//记录该大素因素
			ansNum[ansSize++]=1;//其幂指数只能为1 
		} 
		int ans=0;
		for(int i=0;i<ansSize;i++)
			ans+=ansNum[i];//统计各个素因素的幂指数
		printf("%d\n",ans);//输出 
	}
	return 0;
} 
