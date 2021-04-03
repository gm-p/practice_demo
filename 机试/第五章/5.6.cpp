#include <stdio.h>
#include <vector>
using namespace std;
struct E//�ٽ������е�����Ԫ�ؽṹ��
{
	int next;//����ֱ�����ڵĽ�� 
	int c;//����ñߵ�Ȩֵ�����ȣ� 
};
vector<E> edge[101];//�ڽ�����
bool mark[101];//��ǣ���mark[j]Ϊtrueʱ��ʾ���j�����·�������Ѿ��õ����ý���Ѿ����뼯��k
int Dis[101];//������������mark[i]Ϊtrueʱ����ʾ�ѵõ����·�����ȣ����򣬱�ʾ���дӽ��1������������֪�����·���ﵽ����k��ĳ��㣬�پ���һ���ߵ�����i��·������̵ľ���
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		for(int i=1;i<=n;i++)
			edge[i].clear();//��ʼ���ڽ����� 
		while(m--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			E tmp;
			tmp.c=c;
			tmp.next=b;
			edge[a].push_back(tmp);
			tmp.next=a;
			edge[b].push_back(tmp);//���ڽ���Ϣ�����ڽ���������ԭͼΪ����ͼ����ÿ������Ϣ��Ҫ��ӵ������������������������ 
		}
		for(int i=1;i<=n;i++)//��ʼ��
		{
			Dis[i]=-1;//���о���Ϊ-1�������ɴ�
			mark[i]=false;//���н�㲻���ڼ���k 
		} 
		Dis[1]=0;//�õ�����ĵ�Ϊ���1������Ϊ0
		mark[1]=true;//�����1���뼯��k
		int newP=1;//����k���¼���ĵ�Ϊ���1
		for(int i=1;i<n;i++)//ѭ��n-1�Σ��������·��������˳��ȷ������n-1��������·������
		{
			for(int j=0;j<edge[newP].size();j++)//��������¼��뼯��k�еĽ��ֱ�����ڵı�
			{
				int t=edge[newP][j].next;//�ñߵ���һ�����
				int c=edge[newP][j].c;//�ñߵĳ���
				if(mark[t]==true)
					continue;//����һ�����Ҳ���ڼ���k��������
				if(Dis[t]==-1||Dis[t]>Dis[newP]+c)//���ý���в��ɴ���߸ý����¼���Ľ�㾭��һ���ߵ���ʱ�������������
					Dis[t]=Dis[newP]+c;//�����������Ϣ 
			} 
			int min=123123123;//��Сֵ��ʼ��Ϊһ����������Ϊ����Сֵ��׼��
			for(int j=1;j<=n;j++)//�������н��
			{
				if(mark[j]==true)
					continue;//�������ڼ���k������
				if(Dis[j]==-1)
					continue;//���ý���Բ��ɴ�������
				if(Dis[j]<min)//���ý�㾭�ɽ��1������k�е�ĳ���ھ���һ���ߵ���ʱ����С�ڵ�ǰ��Сֵ
				{
					min=Dis[j];//������Ϊ��Сֵ
					newP=j;//�¼���ĵ��ݶ�Ϊ�õ� 
				}	 
			} 
			mark[newP]=true;//���¼���ĵ���뼯��k��Dis[newP]��Ȼ��ֵ���䣬�����巢���仯�������о�������k�еĽ���پ���һ���ߵ���ʱ�ľ����е���Сֵ��Ϊ�ӽ��1�����newP����̾��� 
		}
		printf("%d\n",Dis[n]);//��� 
	}
	return 0;
} 
