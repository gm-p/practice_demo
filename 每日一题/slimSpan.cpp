/*
�����Kruskal�㷨���˱��Σ���������С������������������Ȩֵ����С��Ȩֵ֮����С��������
ͬ��������Kruskal�㷨��ʵ�ַ��������ò��鼯 
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#define inf 10000000   //��Ȩֵ���Ͻ�

using namespace std;

int m, n;
int p[105];   //p�������ڼ�¼���ڵ� 
int r[105];   //r��������ͳ����rΪ���������м��ж��ٸ��㣬��ʵr�������ȡ������Ϊֱ���ɸ��ڵ�ľ���ֵ�Ϳ�����������е�Ԫ�صĸ���

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

void set_init()   //���鼯��ʼ��
{
	for(int i=1; i<=n; i++)
	{
		p[i] = i;
		r[i] = i;  //��ʼ״̬ÿ���ĸ������Լ������ϸ���Ϊ1 
	} 
} 

/*int set_find(int x)    //���Ұ���x�ļ������ĸ�
{
	while(p[x] >= 0)
		x = p[x];
	return x; 
} 
����Ϊ�ǵݹ�ʵ�֣��ݹ�ʵ������*/

int set_find(int x)
{
	if(p[x] == x)
		return x;
	else
		p[x] = set_find(p[x]);
	return p[x]; 
} 

/*void set_union(int root1, int root2)  //���������Ϻϲ�
{
	p[root1] += p[root2];
	p[root2] = root1;   //�ø�root2���ӵ�root1���� 
} */

//Ϊ��ֹ�����˻����Ľ����union��������
void set_union(int x, int y)  //���������Ϻϲ�
{
	if(r[x] <= r[y])
	{
		p[x] = y;
		r[y] += r[x];  //y��Ϊ�� 
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
			cout<<"0"<<endl;  //2��1�ߵ������������
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
					set_union(px, py);   //ע������ֻ��������������һ����mst��ֻҪ����ͬһ�������оͿ���ѡ�����ߣ������˵���ͬһ������
					k++;
					if(k == 1)  //������С�ı�
						a = e[j].w;
					else if(k == n-1)  //�������ı�Ҳ�����һ����
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
