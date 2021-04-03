#include <stdio.h>
#include <vector>
using namespace std;
struct E //邻接链表元素结构体
{
	int next;
	int c;
	int cost;
} ;
vector<E> edge[1001];//邻接链表
int Dis[1001];//距离数组
int cost[1001];//花费数组
bool mark[1001];//是否属于集合k数组
int main()
{
	int n,m;
	int S,T;//起点，终点
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		for(int i=1;i<=n;i++)
			edge[i].clear();//初始化邻接链表 
		while(m--)
		{
			int a,b,c,cost;
			scanf("%d%d%d%d",&a,&b,&c,&cost);
			E tmp;
			tmp.c=c;
			tmp.cost=cost;//邻接链表中增加了该边的花费信息 
			tmp.next=b;
			edge[a].push_back(tmp);
			tmp.next=a;
			edge[b].push_back(tmp);
		} 
		scanf("%d%d",&S,&T);//输入起点终点信息
		for(int i=1;i<=n;i++)//初始化
		{
			Dis[i]=-1;
			mark[i]=false;
		} 
		Dis[S]=0;
		mark[S]=true;
		int newP=S;//起点为S，将其加入集合K，且其最短距离确定为0
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<edge[newP].size();j++)
			{
				int t=edge[newP][j].next;
				int c=edge[newP][j].c;
				int co=edge[newP][j].cost;//花费 
				if(mark[t]==true)
					continue;
				if(Dis[t]==-1||Dis[t]>Dis[newP]+c||Dis[t]==Dis[newP]+c&&cost[t]>cost[newP]+co)//比较大小时，将距离相同但花费更短也作为更新的条件之一
				{
					Dis[t]=Dis[newP]+c;
					cost[t]=cost[newP]+co;//更新花费 
				} 
			}
			int min=123123123;
			for(int j=1;j<=n;j++)//选择最小值，选择时不用考虑花费的因素，因为距离最近的点的花费已经不可能由于经过其它点而发生改变了
			{
				if(mark[j]==true)
					continue;
				if(Dis[j]==-1)
					continue;
				if(Dis[j]<min)
				{
					min=Dis[j];
					newP=j;
				}
			} 
			mark[newP]=true;
		} 
		printf("%d %d\n",Dis[T],cost[T]);//输出答案 
	} 
	return 0;
} 
