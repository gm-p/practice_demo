//方法一 
/*
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int f[30][1000];
int Path[30][1000];

int w[300];  //质量
int v[300];  //价值

set<int> index;   //存放最终方案

int main()
{
	int i, j, k;
	int t1, t2;
	int n, m;  //n为数量，m为最大重量
	
	while(scanf("%d %d", &n, &m))
	{
		if(n == 0 && m == 0)
			break;
		for(i=1; i<=n; i++)
			scanf("%d %d", &w[i],&v[i]);
		memset(f,-1,sizeof(f));
		memset(Path,0,sizeof(Path));
		
		f[0][0]=0;  //初始化条件，根据f[0][0]推以后的结果
		for(j=0; j<n; j++)    //每次循环选出第j个物品，最多n个 
		{
			for(k=0; k<=m; k++)   //可能的重量为[0,m]
			  if(f[j][k] >= 0)  //方案f[j,k]可行，从f[0][0]开始 
			  {
			     for(i=1; i<=n; i++)
				 	if(f[j][k] + v[i] > f[j+1][k+w[i]] && k+w[i] <= m)  //若f[j+1][k+w[i]]已经有值，则保存较大的一个 
					{
					   t1 = j;
					   t2 = k;
					   while(t1 > 0 && Path[t1][t2] != i)  //验证i是否在前面出现过
					   {
					      t2 -= w[Path[t1][t2]];  //减去前一个元素的重量
						  t1--; 
					   } 
					   if(t1 == 0)  //若i未出现过
					   {
					   	 f[j+1][k+w[i]] = f[j][k] + v[i];
						 Path[j+1][k+w[i]] = i; 
					   } 
					} 	
			  } 
		} 
		int maxNum=0, maxV=0, maxW=0;
		for(i=1; i<=n; i++) 
		{
			for(j=0; j<=m; j++)  //注意必须 = m
			{
				if(maxV < f[i][j])
				{
					maxV = f[i][j];
					maxNum = i; 
					maxW = j;
				} 
			} 
		} 
		cout<<"MAX Value: "<<maxV<<endl;
		cout<<"MAX num: "<<maxNum<<endl;
		index.clear();
		for(i=0; i<maxNum; i++)
		{
			int id = Path[maxNum-i][maxW]; //若直接输出，由于递归则是乱序的
			index.insert(id);
			maxW -= w[id]; 
		} 
		for(set<int>::iterator iter=index.begin(); iter != index.end(); iter++)
			cout<<*iter<<" "; 
		cout<<endl;
	} 
	return 0;
} */



//方法二
#include <iostream>
#include <cstring>
using namespace std;

const int nMax = 400;   //待选物品数 
const int mMax = 10000;  //最大载重

struct
{
	int wei, val;
} node[nMax];

int main()
{
	int m, n, i, w, dp[mMax];
	while(cin>>n>>m)    //n为待选物品数量，m为最大载重量
	{
		if(m==0 && n==0)
			break;
		for(i=1; i<=n; i++)
			cin>>node[i].wei>>node[i].val;
		memset(dp, 0, (m+1)*sizeof(int));
		
		for(i=1; i<=n; i++)
			for(w=m; w>=node[i].wei; w--)
			  if(dp[w] < dp[w-node[i].wei] + node[i].val)
			  	dp[w] = dp[w-node[i].wei] + node[i].val;
				  
		cout<<dp[m]<<endl; 
	} 
	return 0;
} 
