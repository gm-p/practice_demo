#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

int f[30][1000];
//f[j,k]标示：取j个候选人，使其辩空差为k的方案中辩控和最大的那个方案（该方案称为“方案f(j,k)”）的控辩和
int Path[30][1000];   //Path数组用来记录选了哪些人,方案f(j,k)中最后选的那个候选人的编号，记在Path[j][k]中
int P[300];  //控方打分
int D[300];  //辩方打分
int Answer[30];  //存放最终方案的人选

int cmp(const void* a, const void* b)
{
	return *(int *)a - *(int *)b; 
} 
 
int main()
{
	int i, j, k;
	int t1, t2;
	int n, m;
	int nMinP_D;   //辩控双方总分一样时的辩控差
	int iCase = 0;   //测试数据编号
	while(scanf("%d %d", &n, &m))
	{
		if(n == 0 && m == 0)
			break;
		iCase++;
		for(i=1; i<=n; i++)
			scanf("%d %d",&P[i],&D[i]);
		memset(f, -1, sizeof(Path));
		nMinP_D = m*20;  //题目中的辩控差为0，对应于程序中的辩控差为m*20
		f[0][nMinP_D] = 0;
		for(j=0; j<m; j++)   //每次循环选出第j个人，共要选出m人
		{
			for(k=0; k<=nMinP_D*2; k++)   //可能的辩控差为[0, nMinP_D*2]
				if(f[j][k] >= 0)   //方案f[j,k]可行
				{
					for(i=1; i<=n; i++)
						if(f[j][k]+P[i]+D[i] > f[j+1][k+P[i]-D[i]])  //若f[j+1][k+P[i]-D[i]]已经有值，则保存较大的一个
						{
							t1 = j;
							t2 = k;
							while(t1 > 0 && Path[t1][t2] != i)   //验证i是否在前面出现过
							{
								t2 -= P[Path[t1][t2]] - D[Path[t1][t2]];   //减前一个元素的辩控差
								t1--; 
							} 
							if(t1 == 0)
							{
								f[j+1][k+P[i]-D[i]] = f[j][k]+P[i]+D[i];
								Path[j+1][k+P[i]-D[i]] = i; 
							} 
						} 
				} 
		} 
		i = nMinP_D;
		j=0;
		while(f[m][i+j] < 0 && f[m][i-j] < 0)  
			j++;   //计算j
		if(f[m][i+j] > f[m][i-j])
			k = i+ j;  //计算k
		else
		    k = i - j;
		cout<<"Jury #"<<iCase<<endl;
		cout<<"Best jury has value "<<(k-nMinP_D+f[m][k])/2
			<<" for prosecution and value "<<(f[m][k]-k+nMinP_D)/2 <<" for defence:"<<endl;
		for(i=1; i<=m; i++) 
		{
			Answer[i] = Path[m-i+1][k];
			k -= P[Answer[i]] - D[Answer[i]]; 
		} 
		qsort(Answer+1, m, sizeof(int), cmp);
		for(i=1; i<=m; i++)
			cout<<" "<<Answer[i];
		cout<<endl; 
	} 
	return 0;
} 
