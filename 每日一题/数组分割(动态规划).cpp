//http://blog.csdn.net/yangtrees/article/details/8240929

//方法一
/*
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 101
#define MAXSUM 100000
int A[MAXN];
bool dp[MAXN][MAXSUM];
 
//dp[k][s]表示从前k个数中取任意个数，且这些数之和为s的取法是否存在
int main()
{
	int n, i, k1, k2, s, u;
	cin>>n;
	for(i=1; i<=2*n; i++)
		cin>>A[i];
	int sum=0;
	for(i=1; i<=2*n; i++)
		sum += A[i];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = true; 
    //外阶段k1表示第k1个数，内阶段k2表示选取数的个数
	//这跟前面陪审团和0-1背包的方法不太一样，他们是在外阶段（外循环）迭代选取个数，内阶段迭代具体选取哪个数
	//这样做需验证选取的数是否出现过，但是可以通过保存Path[个数][状态和]来存储各个状态
	for(k1=1; k1<=2*n; k1++)   //外阶段k1
	{
		for(k2=k1; k2>=1; k2--)  //内阶段k2
			for(s=1; s<=sum/2; s++)  //状态s
				//有两个决策包含或不包含元素k1
				if(s >= A[k1] && dp[k2-1][s-A[k1]])
					dp[k2][s] = true; 
	} 
	/*根据0-1背包问题改写的方法：事实证明这种方法在不判断选用节点k2 是否使用过的情况下，不可取，
	因为可能会重复调用某一个节点，除非再利用Path[k1][s]保存相应状态的节点。再判断它是否出过，那样的话，
	就需要用dp[k1][s]保存状态和s，也就是说跟第二个坐标一样。 
	for(k1=0; k1<2*n; k1++)   //迭代选取数量
	{
		for(s=0; s<=sum/2; s++)   //状态和sum:s
			if(dp[k1][s] == true)
				for(k2=1; k2<=2*n; k2++)   //选取第k2个
					if(s >= A[k1])
						dp[k1+1][s+A[k2]] = true; 
	} */
	
	//之前的dp[k][s]表示从前k个数中取任意k个数，经过下面的步骤后即表示从前k个数中取任意个数
/*	for(k1=2; k1<=2*n; k1++)
		for(s=1; s<=sum/2; s++)
			if(dp[k1-1][s])
				dp[k1][s] = true;
	//确定最接近的给定值sum/2的和
	for(s=sum/2; s>=1 && !dp[2*n][s]; s--)
		;
		
	cout<<"the difference between two sub array is "<< sum-2*s <<endl;
	
	return 0; 
} */



//方法二
/* dp[i][m]保存状态和 
#include <iostream>
#include <cstring>

using namespace std;

const int nMax = 400;   //待选物品数
const int mMax = 10000; //最大和

struct
{
	int wei;
}node[nMax];

int main()
{
	int m, n, i, w, dp[mMax], sumN=0;
	while(cin>>n)
	{
		if(n==0)
			break;
		for(i=1; i<=2*n; i++)
		{
			cin>>node[i].wei;
			sumN += node[i].wei; 
		} 
		m = sumN/2;
		
		memset(dp, 0, (m+1)*sizeof(int));
		for(i=1; i<=2*n; i++)
			for(w=m; w>=node[i].wei; w--)  
				if(dp[w] < dp[w-node[i].wei] + node[i].wei)
					dp[w] = dp[w-node[i].wei] + node[i].wei;
		
		cout<<dp[m]<<endl;
		cout<<"the difference between two sub array is: "<<sumN - 2*dp[m]<<endl; 
	} 
	return 0;
} */


//解法三：根据公正陪审团问题改写
#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

#define MAXN 101
#define MAXSUM 100000
int A[MAXN];
int dp[MAXN][MAXSUM];
int Path[MAXN][MAXSUM]; 

//dp[k][s]表示取k个数，且和为s的情况下，保存的依然是和s（因为要优化判断）
int main()
{
	int n, i, k1, k2, s, u, t1, t2;
	cin>>n;
	for(i=1; i<=2*n; i++)
		cin>>A[i];
	int sum=0;
	for(i=1; i<=2*n; i++)
		sum += A[i];
	memset(dp, -1, sizeof(dp)); 
	
	dp[0][0] = 0;  //初始状态
	
	for(k1=0; k1<2*n; k1++)   //选取的数量k1
	{
		for(s=0; s<=sum/2; s++)   //状态和s
		 	if(dp[k1][s] >= 0)
			 {
			 	for(k2=1; k2<=2*n; k2++)   //具体选取哪一个k2
				 	if(dp[k1][s] + A[k2] > dp[k1+1][s+A[k2]] && s+A[k2] <= sum/2)
					 {
					 	t1 = k1;
					 	t2 = s;
					 	while(t1 > 0 && Path[t1][t2] != k2)  //验证k2是否在前面出现过
						 {
						 	t2 -= A[Path[t1][t2]];  //减前一个元素的值
							t1--; 
						 } 
						 if(t1 == 0)
						 {
						 	dp[k1+1][s+A[k2]] = dp[k1][s] + A[k2];
							 Path[k1+1][s+A[k2]] = k2;  //k2保存在Path中 
						 } 
					 } 
			 } 
	} 
	
	int maxS=0, maxN=0;
	for(k1=1; k1<=2*n; k1++)
		for(s=1; s<=sum/2; s++)
			if(dp[k1][s] > maxS)
			{
				maxS = dp[k1][s];
				maxN = k1; 
			} 
	cout<<"the count of num: "<<maxN<<" the max sum of the num: "<<maxS <<endl;
	cout<<"the difference between two sub array is : "<<sum-2*maxS<<endl;
	
	set<int> index;
	index.clear();
	for(int i=0; i<maxN; i++)
	{
		int id = Path[maxN-i][maxS];
		index.insert(id);
		maxS -= A[id]; 
	} 
	cout<<endl;
	cout<<"the index of selected num: ";
	for(set<int>::iterator iter=index.begin(); iter!=index.end(); iter++) 
		cout<<*iter<<" ";
	return 0; 
} 




//问题2
/*#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 101
#define MAXSUM 100000
int A[MAXN];
bool dp[MAXN][MAXSUM];

//题目可转换为从2n个数中选出n个数，其和尽量接近于给定值sum/2
int main()
{
	int n, i, k1, k2, s, u;
	cin>>n;
	for(i=1; i<=2*n; i++)
		cin>>A[i];
	int sum=0;
	for(i=1; i<=2*n; i++)
		sum += A[i];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = true;
	//对于dp[k][s]要进行u次决策，由于阶段k的选择受到决策的限制，
	//这里决策选择不允许重复，但阶段可以重复，比较特别
	for(k1=1; k1<=2*n; k1++)   //外阶段k1
		for(k2=min(k1,n); k2>=1; k2--)   //内阶段k2
			for(s=1; s<=sum/2; s++)  //状态s
				if(s >= A[k1] && dp[k2-1][s-A[k1]])  //有两个决策包含或不包含元素k1
					dp[k2][s] = true;
	
	//确定最接近的给定值sum/2的和
	for(s=sum/2; s>=1 && !dp[n][s]; s--)
		;
	cout<<"the difference between two sub array is : "<<sum-2*s<<endl;
	return 0; 
} */
