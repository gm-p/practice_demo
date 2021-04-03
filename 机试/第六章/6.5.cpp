#include <stdio.h>
#include <string.h>
int ans[22];//保存环中每一个被放入的数
bool hash[22];//标记之前已经被放入环中的数
int n;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41};//素数，若需判断一个数是否为素数则在其之中查找，因为输入不大于16，故两数和构成的素数必在该数组内
bool judge(int x) //判断一个数是否为素数
{
	for(int i=0;i<13;i++)
		if(prime[i]==x)
			return true;//在素数数组中查找，若查找成功则该数为素数 
	return false;//否则不是素数 
} 
void check()//检查输出由回溯法枚举得到的解
{
	if(judge(ans[n]+ans[1])==false)
		return ;//判断最后一个数与第一个数的和是否为素数，若不是则直接返回
	for(int i=1;i<=n;i++)//输出解，注意最后一个数字后没有空格
	{
		if(i!=1)
			printf(" ");
		printf("%d",ans[i]);
	} 
	printf("\n");
}
void DFS(int num) //递归枚举，num为当前已经放入环中的数字
{
	if(num>1)//当放入的数字大于一个时
		if(judge(ans[num]+ans[num-1])==false) 
		return ;//判断最后两个数字的和是否为素数，若不是则返回继续枚举第num个数
	if(num==n)//若已经放入了n个数
	{
		check();//检查输出
		return ;//返回，继续枚举下一组解 
	} 
	for(int i=2;i<=n;i++)//放入一个数
	{
		if(hash[i]==false)//若i还没有被放入环中
		{
			hash[i]=true;//标记i为已经使用
			ans[num+1]=i;//将这个数字放入ans数组中
			DFS(num+1);//继续尝试放入下一个数
			hash[i]=false;//当回溯回枚举该位数字时，将i重新标记为未使用 
		} 
	} 
} 
int main()
{
	int cas=0;//记录Case数
	while(scanf("%d",&n)!=EOF)
	{
		cas++;//Case数递增
		for(int i=0;i<22;i++)
			hash[i]=false;//初始化标记所有数字为未被使用
		ans[1]=1;//第一个数字恒定为1
		printf("Case %d:\n",cas);//输出Case数
		hash[1]=true;//标记1被使用
		DFS(1);//继续尝试放入下一个数字
		printf("\n");//输出换行 
	} 
	return 0;
}
