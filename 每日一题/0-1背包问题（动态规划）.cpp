//����һ 
/*
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int f[30][1000];
int Path[30][1000];

int w[300];  //����
int v[300];  //��ֵ

set<int> index;   //������շ���

int main()
{
	int i, j, k;
	int t1, t2;
	int n, m;  //nΪ������mΪ�������
	
	while(scanf("%d %d", &n, &m))
	{
		if(n == 0 && m == 0)
			break;
		for(i=1; i<=n; i++)
			scanf("%d %d", &w[i],&v[i]);
		memset(f,-1,sizeof(f));
		memset(Path,0,sizeof(Path));
		
		f[0][0]=0;  //��ʼ������������f[0][0]���Ժ�Ľ��
		for(j=0; j<n; j++)    //ÿ��ѭ��ѡ����j����Ʒ�����n�� 
		{
			for(k=0; k<=m; k++)   //���ܵ�����Ϊ[0,m]
			  if(f[j][k] >= 0)  //����f[j,k]���У���f[0][0]��ʼ 
			  {
			     for(i=1; i<=n; i++)
				 	if(f[j][k] + v[i] > f[j+1][k+w[i]] && k+w[i] <= m)  //��f[j+1][k+w[i]]�Ѿ���ֵ���򱣴�ϴ��һ�� 
					{
					   t1 = j;
					   t2 = k;
					   while(t1 > 0 && Path[t1][t2] != i)  //��֤i�Ƿ���ǰ����ֹ�
					   {
					      t2 -= w[Path[t1][t2]];  //��ȥǰһ��Ԫ�ص�����
						  t1--; 
					   } 
					   if(t1 == 0)  //��iδ���ֹ�
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
			for(j=0; j<=m; j++)  //ע����� = m
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
			int id = Path[maxNum-i][maxW]; //��ֱ����������ڵݹ����������
			index.insert(id);
			maxW -= w[id]; 
		} 
		for(set<int>::iterator iter=index.begin(); iter != index.end(); iter++)
			cout<<*iter<<" "; 
		cout<<endl;
	} 
	return 0;
} */



//������
#include <iostream>
#include <cstring>
using namespace std;

const int nMax = 400;   //��ѡ��Ʒ�� 
const int mMax = 10000;  //�������

struct
{
	int wei, val;
} node[nMax];

int main()
{
	int m, n, i, w, dp[mMax];
	while(cin>>n>>m)    //nΪ��ѡ��Ʒ������mΪ���������
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
