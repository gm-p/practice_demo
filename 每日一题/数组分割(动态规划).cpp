//http://blog.csdn.net/yangtrees/article/details/8240929

//����һ
/*
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 101
#define MAXSUM 100000
int A[MAXN];
bool dp[MAXN][MAXSUM];
 
//dp[k][s]��ʾ��ǰk������ȡ�������������Щ��֮��Ϊs��ȡ���Ƿ����
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
    //��׶�k1��ʾ��k1�������ڽ׶�k2��ʾѡȡ���ĸ���
	//���ǰ�������ź�0-1�����ķ�����̫һ��������������׶Σ���ѭ��������ѡȡ�������ڽ׶ε�������ѡȡ�ĸ���
	//����������֤ѡȡ�����Ƿ���ֹ������ǿ���ͨ������Path[����][״̬��]���洢����״̬
	for(k1=1; k1<=2*n; k1++)   //��׶�k1
	{
		for(k2=k1; k2>=1; k2--)  //�ڽ׶�k2
			for(s=1; s<=sum/2; s++)  //״̬s
				//���������߰����򲻰���Ԫ��k1
				if(s >= A[k1] && dp[k2-1][s-A[k1]])
					dp[k2][s] = true; 
	} 
	/*����0-1���������д�ķ�������ʵ֤�����ַ����ڲ��ж�ѡ�ýڵ�k2 �Ƿ�ʹ�ù�������£�����ȡ��
	��Ϊ���ܻ��ظ�����ĳһ���ڵ㣬����������Path[k1][s]������Ӧ״̬�Ľڵ㡣���ж����Ƿ�����������Ļ���
	����Ҫ��dp[k1][s]����״̬��s��Ҳ����˵���ڶ�������һ���� 
	for(k1=0; k1<2*n; k1++)   //����ѡȡ����
	{
		for(s=0; s<=sum/2; s++)   //״̬��sum:s
			if(dp[k1][s] == true)
				for(k2=1; k2<=2*n; k2++)   //ѡȡ��k2��
					if(s >= A[k1])
						dp[k1+1][s+A[k2]] = true; 
	} */
	
	//֮ǰ��dp[k][s]��ʾ��ǰk������ȡ����k��������������Ĳ���󼴱�ʾ��ǰk������ȡ�������
/*	for(k1=2; k1<=2*n; k1++)
		for(s=1; s<=sum/2; s++)
			if(dp[k1-1][s])
				dp[k1][s] = true;
	//ȷ����ӽ��ĸ���ֵsum/2�ĺ�
	for(s=sum/2; s>=1 && !dp[2*n][s]; s--)
		;
		
	cout<<"the difference between two sub array is "<< sum-2*s <<endl;
	
	return 0; 
} */



//������
/* dp[i][m]����״̬�� 
#include <iostream>
#include <cstring>

using namespace std;

const int nMax = 400;   //��ѡ��Ʒ��
const int mMax = 10000; //����

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


//�ⷨ�������ݹ��������������д
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

//dp[k][s]��ʾȡk�������Һ�Ϊs������£��������Ȼ�Ǻ�s����ΪҪ�Ż��жϣ�
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
	
	dp[0][0] = 0;  //��ʼ״̬
	
	for(k1=0; k1<2*n; k1++)   //ѡȡ������k1
	{
		for(s=0; s<=sum/2; s++)   //״̬��s
		 	if(dp[k1][s] >= 0)
			 {
			 	for(k2=1; k2<=2*n; k2++)   //����ѡȡ��һ��k2
				 	if(dp[k1][s] + A[k2] > dp[k1+1][s+A[k2]] && s+A[k2] <= sum/2)
					 {
					 	t1 = k1;
					 	t2 = s;
					 	while(t1 > 0 && Path[t1][t2] != k2)  //��֤k2�Ƿ���ǰ����ֹ�
						 {
						 	t2 -= A[Path[t1][t2]];  //��ǰһ��Ԫ�ص�ֵ
							t1--; 
						 } 
						 if(t1 == 0)
						 {
						 	dp[k1+1][s+A[k2]] = dp[k1][s] + A[k2];
							 Path[k1+1][s+A[k2]] = k2;  //k2������Path�� 
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




//����2
/*#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 101
#define MAXSUM 100000
int A[MAXN];
bool dp[MAXN][MAXSUM];

//��Ŀ��ת��Ϊ��2n������ѡ��n��������;����ӽ��ڸ���ֵsum/2
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
	//����dp[k][s]Ҫ����u�ξ��ߣ����ڽ׶�k��ѡ���ܵ����ߵ����ƣ�
	//�������ѡ�������ظ������׶ο����ظ����Ƚ��ر�
	for(k1=1; k1<=2*n; k1++)   //��׶�k1
		for(k2=min(k1,n); k2>=1; k2--)   //�ڽ׶�k2
			for(s=1; s<=sum/2; s++)  //״̬s
				if(s >= A[k1] && dp[k2-1][s-A[k1]])  //���������߰����򲻰���Ԫ��k1
					dp[k2][s] = true;
	
	//ȷ����ӽ��ĸ���ֵsum/2�ĺ�
	for(s=sum/2; s>=1 && !dp[n][s]; s--)
		;
	cout<<"the difference between two sub array is : "<<sum-2*s<<endl;
	return 0; 
} */
