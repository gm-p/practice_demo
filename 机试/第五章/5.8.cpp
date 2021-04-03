#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> edge[501];//�ڽ�������Ϊ�߲�����Ȩֵ��ֻ�豣�������ڽӵĽ���ż��ɣ�����vector�е�Ԫ��Ϊint
queue<int> Q;//�������Ϊ0�Ľ��Ķ���
int main()
{
	int inDegree[501];//ͳ��ÿ���������
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		for(int i=0;i<n;i++)//��ʼ�����н�㣬ע�Ȿ��������0��n-1 
		{
			inDegree[i]=0;//��ʼ�������Ϣ�����н����Ⱦ�Ϊ0
			edge[i].clear();//����ڽ����� 
		}
		while(m--)
		{
			int a,b;
			scanf("%d%d",&a,&b);//����һ����aָ��b�������
			inDegree[b]++;//�ֳ�����һ����ͷָ��b�ıߣ��ۼӽ��b�����
			edge[a].push_back(b);//��b����a���ڽ����� 
		}
		while(Q.empty()==false)
			Q.pop();//�����зǿգ���һֱ������ͷԪ�أ��ò�����Ŀ��Ϊ��ն��������е�Ԫ�أ�����Ϊ��һ��������������������ݣ�
		for(int i=0;i<n;i++)//ͳ�����н������
		{
			if(inDegree[i]==0)
				Q.push(i);//��������Ϊ0������������ 
		} 
		int cnt=0;//����������ʼֵΪ0�������ۼ��Ѿ�ȷ���������еĽ�����
		while(Q.empty()==false)//�����������Ϊ0�Ľ��δ��ȡ�꣬�ظ�
		{
			int nowP=Q.front();//������ͷ����ţ���������Ҫ���ȷ�����������У��ʲ���������Ҫ�����ȷ�������˴����򽫸ý������ŷ����Ѿ�ȷ������������֮��
			Q.pop();//������ͷԪ��
			cnt++;//��ȷ���Ľ�������һ
			for(int i=0;i<edge[nowP].size();i++)//���ý���Լ�����Ϊ��β�����б�ȥ��
			{
				inDegree[edge[nowP][i]]--;//ȥ��ĳ���ߺ󣬸ñ���ָ��̽����ȼ�һ
				if(inDegree[edge[nowP][i]]==0)//���ý����ȱ�Ϊ0 
					Q.push(edge[nowP][i]);//���������е��� 
			} 
		} 
		if(cnt==n)
			puts("YES");//�����н�㶼�ܱ�ȷ���������У���ԭͼΪ�����޻�ͼ
		else 
			puts("NO");//����ԭͼΪ�������޻�ͼ 
	} 
	return 0;
} 
