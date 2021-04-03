#include <stdio.h>
int prime[10000];//����ɸ�õ�����
int primeSize;//����������ĸ���
bool mark[10001];//��mark[x]Ϊtrue�����ʾ����x�ѱ���ǳɷ�����
void init()//����ɸѡ
{
	for(int i=1;i<=10000;i++)
		mark[i]=false;//��ʼ�����������־�û�����
	primeSize=0;//�õ�����������Ϊ0
	for(int i=2;i<=10000;i++)//���α���2��10000��������
	{
		if(mark[i]==true)
			continue;//���������Ѿ�����ǣ�������
		prime[primeSize++]=i; 
		for(int j=i*i;j<=10000;j+=i)//�������������б�������ǳɷ�����
			mark[j]=true; 
	}
} 
int main()
{
	init();//�ڳ���һ��ʼ����ȡ��2��10000����������
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		bool isOutput=false;//��ʾ�Ƿ�����˷�������������
		for(int i=0;i<primeSize;i++)//���α����õ�����������
		  if(prime[i]<n&&prime[i]%10==1)//���Ե�ǰ�����Ƿ��������
		  {
		  	if(isOutput==false)//����ǰ���Ϊ��һ����������֣������Ѿ�����˷������������֣��Ҹ�����ǰ������ո�
			  {
			  	isOutput=true;
			  	printf("%d",prime[i]);
			  } 
			else
				printf(" %d",prime[i]);
		  }
		  if(isOutput==false)//��ʼ�ղ����ڷ�������������
		  	printf("-1\n");//���-1������
		  else
		  	printf("\n");//���� 
	} 
	return 0;
}
