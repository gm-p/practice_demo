#include <stdio.h>
#include <vector>
using namespace std;
struct E//临街链表中的链表元素结构体
{
	int next;//代表直接相邻的结点 
	int c;//代表该边的权值（长度） 
};
vector<E> edge[101];//邻接链表
bool mark[101];//标记，当mark[j]为true时表示结点j的最短路径长度已经得到，该结点已经加入集合k
int Dis[101];//距离向量，当mark[i]为true时，表示已得的最短路径长度；否则，表示所有从结点1出发，经过已知的最短路径达到集合k的某结点，再经过一条边到达结点i的路径中最短的距离
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		for(int i=1;i<=n;i++)
			edge[i].clear();//初始化邻接链表 
		while(m--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			E tmp;
			tmp.c=c;
			tmp.next=b;
			edge[a].push_back(tmp);
			tmp.next=a;
			edge[b].push_back(tmp);//将邻接信息加入邻接链表，由于原图为无向图，故每条边信息都要添加到其两个顶点的两条单链表中 
		}
		for(int i=1;i<=n;i++)//初始化
		{
			Dis[i]=-1;//所有距离为-1，即不可达
			mark[i]=false;//所有结点不属于集合k 
		} 
		Dis[1]=0;//得到最近的点为结点1，长度为0
		mark[1]=true;//将结点1加入集合k
		int newP=1;//集合k中新加入的点为结点1
		for(int i=1;i<n;i++)//循环n-1次，按照最短路径递增的顺序确定其他n-1个点的最短路径长度
		{
			for(int j=0;j<edge[newP].size();j++)//遍历与该新加入集合k中的结点直接相邻的边
			{
				int t=edge[newP][j].next;//该边的另一个结点
				int c=edge[newP][j].c;//该边的长度
				if(mark[t]==true)
					continue;//若另一个结点也属于集合k，则跳过
				if(Dis[t]==-1||Dis[t]>Dis[newP]+c)//若该结点尚不可达，或者该结点从新加入的结点经过一条边到达时比以往距离更短
					Dis[t]=Dis[newP]+c;//更新其距离信息 
			} 
			int min=123123123;//最小值初始化为一个大整数，为找最小值做准备
			for(int j=1;j<=n;j++)//遍历所有结点
			{
				if(mark[j]==true)
					continue;//若其属于集合k则跳过
				if(Dis[j]==-1)
					continue;//若该结点仍不可达则跳过
				if(Dis[j]<min)//若该结点经由结点1至集合k中的某点在经过一条边到达时距离小于当前最小值
				{
					min=Dis[j];//更新其为最小值
					newP=j;//新加入的点暂定为该点 
				}	 
			} 
			mark[newP]=true;//将新加入的点加入集合k，Dis[newP]虽然数值不变，但意义发生变化，由所有经过集合k中的结点再经过一条边到达时的距离中的最小值变为从结点1到结点newP的最短距离 
		}
		printf("%d\n",Dis[n]);//输出 
	}
	return 0;
} 
