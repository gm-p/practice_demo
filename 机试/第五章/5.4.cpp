#include<stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define N 101
int Tree[N];
int findRoot(int x)
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
struct Edge
{
	int a,b;
	double cost;//权值变为长度，故改用浮点数
	bool operator<(const Edge &A)const
	{
		return cost<A.cost;
	} 
}edge[6000];
struct Point//点结构体
{
	double x,y;
	double getDistance(Point A)//计算点之间的距离
	{
		double tmp=(x-A.x)*(x-A.x)+(y-A.y)*(y-A.y);
		return sqrt(tmp);
	} 
}list[101];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%lf%lf",&list[i].x,&list[i].y);//输入
		int size=0;//抽象出的边的总数
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)//连接两点的线段抽象成边
			{
				edge[size].a=i;
				edge[size].b=j;//该边的两个顶点编号
				edge[size].cost=list[i].getDistance(list[j]);//边权值为两点之间的长度
				size++;//边的总数增加 
			} //遍历所有的点对 
		} 
		sort(edge,edge+size);//对边按权值递增排序
		for(int i=1;i<=n;i++)
			Tree[i]=-1;
		double ans=0;
		for(int i=0;i<size;i++)
		{
			int a=findRoot(edge[i].a);
			int b=findRoot(edge[i].b);
			if(a!=b)
			{
				Tree[a]=b;
				ans+=edge[i].cost;
			}
		}//最小生成树
		printf("%.2lf\n",ans);//输出 
	}
	return 0;
}
