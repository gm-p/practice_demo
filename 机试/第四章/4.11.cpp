#include <stdio.h>
#include <string.h>
bool mark[1010];
int prime[1010];
int primeSize;
void init()
{
	primeSize=0;
	for(int i=2;i<=1000;i++)
	{
		if(mark[i])
			continue;
		//mark[i]=true;
		prime[primeSize++]=i;
		for(int j=i*i;j<=1000;j+=i)
			mark[j]=true;
	}
}//ɸѡ��0��1000��Χ�ڵ���������
int cnt[1010];//cnt[i]������ʾ��prime[i]�������������n!�е�����������n!�ֽ���������������prime[i]����Ӧ����ָ��������Ϊ0
int cnt2[1010];//cnt2[i]������ʾ��prime[i]�������������a�е�������
int main()
{
	int n,a;
	init();
	while(scanf("%d%d",&n,&a)==2)
	{
		for(int i=0;i<primeSize;i++)
			cnt[i]=cnt2[i]=0;//���������������㣬Ϊ�µ�һ�ηֽ���׼��
		for(int i=0;i<primeSize;i++) //��n!�ֽ�������������ÿһ��0��1000������
		{
			int t=n;//����ʱ����t����n��ֵ
			while(t)//ȷ������prime[i]��n�е�������
			{
				cnt[i]+=t/prime[i];
				t=t/prime[i];
			} //���μ���t/prime[i]^k,�ۼ���ֵ��ֱ��t/prime[i]^k��Ϊ0 
		} 
		int ans=123123123;//�𰸳�ʼֵΪһ����������Ϊȡ��Сֵ��׼��
		for(int i=0;i<primeSize;i++)//��a�ֽ�������
		{
			while(a%prime[i]==0)
			{
				cnt2[i]++;
				a/=prime[i];
			}//����a��������prime[i]��Ӧ����ָ��
			if(cnt2[i]==0)//�����������ܴ�a�зֽ⵽�������Ӧ��ָ��Ϊ0�����䲻Ӱ�������ԣ�����
				continue;
			if(cnt[i]/cnt[i]<ans) //��������prime[i]��������������������
				ans=cnt[i]/cnt2[i];//ͳ����Щ�̵���Сֵ 
		} 
		printf("%d\n",ans);//���̼�Ϊ���� 
	}
	return 0;
} 
