//http://blog.csdn.net/yangtrees/article/details/8187246
//分别从不同位置将原数据划分成两个字串，然后分别求最大连续子串和，然后求和，最后比较输出最大值
//动态规划

#include <iostream>
#include <cstring> 
using namespace std;

int data[32];
int sumCal[100][100];
int n;

int calmax(int low, int high)  //求连续子串最大和
{
	if(sumCal[low][high] != 0)
		return sumCal[low][high]; 
		
	int maxTohere=0, maxAll=0;
	for(int i=low; i<=high; i++)
	{
		maxTohere += data[i];
		if(maxTohere < 0)
			maxTohere = 0;
		if(maxTohere > maxAll)
			maxAll = maxTohere; 
	} 
	sumCal[low][high] = maxAll;
	return sumCal[low][high]; 
} 

int divide(int k)
{
	int sum1=0, sum2=0, sum=0;
	sum1 = calmax(0, k);
	sum2 = calmax(k+1, n-1);
	sum = sum1 + sum2;
	return sum; 
} 

int main()
{
	memset(data, -1, sizeof(data));
	
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>data[i];
	int max=0, tmp=0;
	for(int i=0; i<n; i++)
	{
		tmp = divide(i);  //从不同位置划分成两个子串 
		if(tmp > max)
			max = tmp; 
	} 
	cout<<max;
	return 0;
} 
