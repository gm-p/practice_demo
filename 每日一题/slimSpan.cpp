/*
此题对Kruskal算法做了变形，不是求最小生成树，而是求最大边权值与最小边权值之差最小的生成树
同样可以用Kruskal算法的实现方法，采用并查集 
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#define inf 10000000   //边权值的上界

using namespace std;

int m, n;
int p[105];   //p数组用于记录父节点 
int r[105];   //r数组用于统计以r为根的子树中间有多少个点，其实r数组可以取消，因为直接由根节点的绝对值就可以这个集合中的元素的个数

struct edge
{
	int u;
	int v;
	int w;
}e[5000]; 

bool cmp(const edge& e1, const edge& e2)
{
	return e1.w < e2.w;
} 

void set_init()   //并查集初始化
{
	for(int i=1; i<=n; i++)
	{
		p[i] = i;
		r[i] = i;  //初始状态每个的根就是自己，集合个数为1 
	} 
} 

/*int set_find(int x)    //查找包含x的集合树的根
{
	while(p[x] >= 0)
		x = p[x];
	return x; 
} 
以上为非递归实现，递归实现如下*/

int set_find(int x)
{
	if(p[x] == x)
		return x;
	else
		p[x] = set_find(p[x]);
	return p[x]; 
} 

/*void set_union(int root1, int root2)  //将两个集合合并
{
	p[root1] += p[root2];
	p[root2] = root1;   //用根root2连接到root1下面 
} */

//为防止树的退化，改进版的union操作如下
void set_union(int x, int y)  //将两个集合合并
{
	if(r[x] <= r[y])
	{
		p[x] = y;
		r[y] += r[x];  //y作为根 
	} 
	else
	{
		p[y] = x;
		r[x] += r[y]; 
	} 
} 

int main()
{
	int i, j, k, ans, px, py, a, b, temp;
	while(cin>>n>>m)
	{
		if(n == 0 && m == 0)
			break;
		for(i=0; i<m; i++)
			cin>>e[i].u>>e[i].v>>e[i].w;
		if(n == 2 && m == 1)
		{
			cout<<"0"<<endl;  //2点1边的情况单独处理
			continue; 
		} 
		sort(e, e+m, cmp);
		ans = inf;
		for(i=0; i<m; i++)
		{
			k=0;
			set_init();
			for(j=i; j<m; j++)
			{
				px = set_find(e[j].u);
				py = set_find(e[j].v);
				if(px != py)
				{
					set_union(px, py);   //注意这里只是求生成树，不一定是mst，只要不在同一个集合中就可以选这条边，两个端点变成同一个集合
					k++;
					if(k == 1)  //这是最小的边
						a = e[j].w;
					else if(k == n-1)  //这是最大的边也是最后一条边
					{
						b = e[j].w;
						temp = b - a;
						if(temp < ans)
							ans = temp;
						break; 
					} 
				} 
			} 
		} 
		if(ans == inf)
			cout<<"-1"<<endl;
		else
			cout<<ans<<endl; 
	} 
	return 0;
} 
