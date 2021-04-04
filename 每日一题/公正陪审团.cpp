#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

int f[30][1000];
//f[j,k]��ʾ��ȡj����ѡ�ˣ�ʹ���ղ�Ϊk�ķ����б�غ������Ǹ��������÷�����Ϊ������f(j,k)�����Ŀر��
int Path[30][1000];   //Path����������¼ѡ����Щ��,����f(j,k)�����ѡ���Ǹ���ѡ�˵ı�ţ�����Path[j][k]��
int P[300];  //�ط����
int D[300];  //�緽���
int Answer[30];  //������շ�������ѡ

int cmp(const void* a, const void* b)
{
	return *(int *)a - *(int *)b; 
} 
 
int main()
{
	int i, j, k;
	int t1, t2;
	int n, m;
	int nMinP_D;   //���˫���ܷ�һ��ʱ�ı�ز�
	int iCase = 0;   //�������ݱ��
	while(scanf("%d %d", &n, &m))
	{
		if(n == 0 && m == 0)
			break;
		iCase++;
		for(i=1; i<=n; i++)
			scanf("%d %d",&P[i],&D[i]);
		memset(f, -1, sizeof(Path));
		nMinP_D = m*20;  //��Ŀ�еı�ز�Ϊ0����Ӧ�ڳ����еı�ز�Ϊm*20
		f[0][nMinP_D] = 0;
		for(j=0; j<m; j++)   //ÿ��ѭ��ѡ����j���ˣ���Ҫѡ��m��
		{
			for(k=0; k<=nMinP_D*2; k++)   //���ܵı�ز�Ϊ[0, nMinP_D*2]
				if(f[j][k] >= 0)   //����f[j,k]����
				{
					for(i=1; i<=n; i++)
						if(f[j][k]+P[i]+D[i] > f[j+1][k+P[i]-D[i]])  //��f[j+1][k+P[i]-D[i]]�Ѿ���ֵ���򱣴�ϴ��һ��
						{
							t1 = j;
							t2 = k;
							while(t1 > 0 && Path[t1][t2] != i)   //��֤i�Ƿ���ǰ����ֹ�
							{
								t2 -= P[Path[t1][t2]] - D[Path[t1][t2]];   //��ǰһ��Ԫ�صı�ز�
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
			j++;   //����j
		if(f[m][i+j] > f[m][i-j])
			k = i+ j;  //����k
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
