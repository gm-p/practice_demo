#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> edge[501];//邻接链表，因为边不存在权值，只需保存与其邻接的结点编号即可，所以vector中的元素为int
queue<int> Q;//保存入度为0的结点的队列
int main()
{
	int inDegree[501];//统计每个结点的入度
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		for(int i=0;i<n;i++)//初始化所有结点，注意本题结点编号由0到n-1 
		{
			inDegree[i]=0;//初始化入度信息，所有结点入度均为0
			edge[i].clear();//清空邻接链表 
		}
		while(m--)
		{
			int a,b;
			scanf("%d%d",&a,&b);//读入一条由a指向b的有向边
			inDegree[b]++;//又出现了一条弧头指向b的边，累加结点b的入度
			edge[a].push_back(b);//将b加入a的邻接链表 
		}
		while(Q.empty()==false)
			Q.pop();//若队列非空，则一直弹出对头元素，该操作的目的为清空队列中所有的元素（可能为上一组测试数据中遗留的数据）
		for(int i=0;i<n;i++)//统计所有结点的入度
		{
			if(inDegree[i]==0)
				Q.push(i);//若结点入度为0，则将其放入队列 
		} 
		int cnt=0;//计数器，初始值为0，用于累加已经确定拓扑序列的结点个数
		while(Q.empty()==false)//当队列中入度为0的结点未被取完，重复
		{
			int nowP=Q.front();//读出队头结点编号，本例不需要求出确定的拓扑序列，故不做处理；若要求求出确定的拓扑次序，则将该结点紧接着放在已经确定的拓扑序列之后
			Q.pop();//弹出队头元素
			cnt++;//被确定的结点个数加一
			for(int i=0;i<edge[nowP].size();i++)//将该结点以及以其为弧尾的所有边去除
			{
				inDegree[edge[nowP][i]]--;//去除某条边后，该边所指后继结点入度减一
				if(inDegree[edge[nowP][i]]==0)//若该结点入度变为0 
					Q.push(edge[nowP][i]);//将其放入队列当中 
			} 
		} 
		if(cnt==n)
			puts("YES");//若所有结点都能被确定拓扑序列，则原图为有向无环图
		else 
			puts("NO");//否则，原图为非有向无环图 
	} 
	return 0;
} 
