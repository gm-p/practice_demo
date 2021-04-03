#include <stdio.h>
bool mark[100001];
int prime[100001];
int primeSize;
void init()
{
	primeSize=0;
	for(int i=2;i<=100000;i++)
	{
		if(mark[i]==true)
			continue;
		prime[primeSize++]=i;
		if(i>=1000)
			continue;
		for(int j=i*i;j<=100000;j+=i)
			mark[j]=true;
	}
}//����������һ�£�������ɸ��ɸѡ��2��100000�ڵ���������
int main()
{
	init();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int ansPrime[30];//��˳�򱣴�ֽ����������
		int ansSize=0;//�ֽ�������صĸ���
		int ansNum[30];//����ֽ���������ض�Ӧ����ָ��
		for(int i=0;i<primeSize;i++) //���β���ÿһ������
		{
			if(n%prime[i]==0)//�����������������ֽ���
			{
				ansPrime[ansSize]=prime[i];//�������Ϊ������
				ansNum[ansSize]=0;//��ʼ����ָ��Ϊ0
				while(n%prime[i]==0)//�ӱ��������н��������ֽ��������ͳ������ָ�� 
				{
					ansNum[ansSize]++;
					n/=prime[i];
				} 
				ansSize++;//�����ظ�������
				if(n==1)
					break;//���ѱ��ֽ��1����ֽ���ǰ��ֹ 
			} 
		} 
		if(n!=1)//��������2��100000�����������أ�n��δ���ֽ���1����ʣ�������һ����nһ������100000��������
		{
			ansPrime[ansSize]=n;//��¼�ô�������
			ansNum[ansSize++]=1;//����ָ��ֻ��Ϊ1 
		} 
		int ans=0;
		for(int i=0;i<ansSize;i++)
			ans+=ansNum[i];//ͳ�Ƹ��������ص���ָ��
		printf("%d\n",ans);//��� 
	}
	return 0;
} 
