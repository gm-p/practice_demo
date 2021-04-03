#include <stdio.h>
using namespace std;
#define N 1000
int Tree[N];
int findRoot(int x)//����ĳ������������ĸ����
{
	if(Tree[x]==-1)
		return x;
	else
	{
		int tmp=findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}
int main()
{
	int n,m;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		scanf("%d",&m);
		for(int i=1;i<=n;i++)
			Tree[i]=-1;//��ʼʱ�����н�㶼�ǹ����ļ��ϣ��������ڼ���ֻ��һ����㣬�䱾���������������� 
		while(m--!=0)//�������Ϣ 
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);//���ұߵ������������ڼ�����Ϣ 
			if(a!=b)//���������㲻��ͬһ��������ϲ����������� 
				Tree[a]=b;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(Tree[i]==-1)//ͳ�����н���и����ĸ��� 
				ans++;
		printf("%d\n",ans-1);//�𰸼�Ϊ��ans�����ϼ����޽�ans-1����·����ʹ ���н����ͨ 
	}
	return 0;
}
