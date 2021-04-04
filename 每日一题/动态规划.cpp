/*http://blog.csdn.net/yangtrees/article/details/8191707
动态规划是通过组合子问题的解而解决整个问题
动态规划的4个步骤：
1.描述最优解结构
2.递归定义最优解的值
3.按自底向上方式计算最优解
4.由计算出的结果构造最优解(1-3步是基础，第4步可以略去) 
*/

//1.装配线调度
/*
#include <iostream>
#include <cstring>

using namespace std;

int minT[2][100];
int a[2][100], t[2][100];
int e[2]={2, 4}, x[2]={3, 2};

int cal(int k, int num)
{
	if(num == 1)
	{
		minT[k][1] = e[k] + a[k][1];
		return minT[k][1]; 
	} 
	if(minT[k][num] > 0)
		return minT[k][num];
	else
	{
		minT[k][num] = min(cal(k, num-1), cal((k+1)%2, num-1) + t[(k+1)%2][num-1]) + a[k][num];
		return minT[k][num]; 
	} 
} 

int main()
{
	memset(minT, 0, sizeof(minT));
	int count;
	cin>>count;
	cout<<"a & t:"<<endl;
	for(int i=1; i<=count; i++)
		cin>>a[0][i];
	for(int i=1; i<=count; i++)
		cin>>a[1][i];
	for(int i=1; i<=count-1; i++)
		cin>>t[0][i];
	for(int i=1; i<=count-1; i++)
		cin>>t[1][i];
		
	int minCost = min(cal(0,count)+x[0], cal(1,count)+x[1]);
	cout<<"MIN:"<<minCost<<endl;
	return 0; 
} */


//2.矩阵链乘法
/*
#include <iostream>
#include <cstring>
using namespace std;
#define INF 100000000;

double s[100][100];
int p[101];

double minMul(int low, int high)
{
	if(low == high)
		return 0;
	if(s[low][high] > 0)
		return s[low][high];
	double minTmp = INF;
	double tmp;
	for(int k=low; k<high; k++)
	{
		tmp = minMul(low, k) + minMul(k+1, high) + p[low-1]*p[k]*p[high];
		if(tmp < minTmp)
			minTmp = tmp; 
	} 
	s[low][high] = minTmp;
	return minTmp; 
} 

int main()
{
	memset(s, 0, sizeof(s));
	int n;
	cin>>n;
	for(int i=0; i<=n; i++)
		cin>>p[i];
	int left, right;
	cin>> left >> right;
	double minM = minMul(left, right);
	cout<<minM<<endl; 
} */


//3.最长公共子序列
/*
给出两个序列，要求给出这两个序列中的最长公共子序列长度，可以不连续，但必须
按顺序a="ABCBDAB", b="BDCABA" 的最长公共子序列长度为"BCBA" 
*/ 
/*
#include <iostream>
#include <string>

using namespace std;

string a="ABCBDAB", b="BDCABA";
int A[100][100];

int main()
{
	int la = a.length();
	int lb = b.length();
	for(int i=0; i<la; i++)
	{
		for(int j=0; j<lb; j++)
		{
			if(i==0 || j==0)
			{
				if(a[i] == b[j])
				   A[i][j] = 1;
				else
				   A[i][j] = 0; 
			} 
			else
			{
				if(a[i] != b[j])
				   A[i][j] = max(A[i-1][j], A[i][j-1]);
				else
				   A[i][j] = A[i-1][j-1] + 1; 
			} 
		} 
	} 
	cout<<A[la-1][lb-1]<<endl;
	return 0; 
} */


//4.构造最优二叉查找树

#include <iostream>
#include <cstring>
#define INF 1000000;
using namespace std;

float p[100], q[100];
float w[100][100], e[100][100];

float calW(int i, int j)
{
	if(w[i][j] > 0)
		return w[i][j];
	if(i > j)
	{
		w[i][j] = q[j];
		return w[i][j]; 
	} 
	float minw=INF;
	for(int r=i; r<=j; r++)
	{
		w[i][j] = calW(i, r-1) + p[r] + calW(r+1, j);
		if(w[i][j] < minw)
			minw = w[i][j]; 
	} 
	w[i][j] = minw;
	return w[i][j]; 
} 

float calE(int i, int j)
{
	if(e[i][j] > 0)
		return e[i][j];
	if(i > j)
	{
		e[i][j] = calW(i,j);
		return e[i][j]; 
	} 
	float minE = INF;
	for(int r=i; r<=j; r++)
	{
		e[i][j] = calE(i, r-1) + calW(i, j) + calE(r+1,j);
		if(e[i][j] < minE)
			minE = e[i][j]; 
	} 
	e[i][j] = minE;
	return e[i][j]; 
} 

int main()
{
	int n;
	memset(p, 0, sizeof(p));
	memset(q, 0, sizeof(q));
	cin>>n;
	for(int i=1; i<n; i++)
		cin>>p[i];
	for(int i=0; i<n; i++)
		cin>>q[i];
	float all15 = calE(1, 5);
	cout<<all15<<endl;
	return 0; 
} 

