//菜鸟级 
/*
#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int N, m;
map<int, set<int> > S;

set<int>& f(int i)
{
	if(!S[i].empty())
		return S[i];
	for(int x=1; x<=i/2; x++)
	{
		if( (x&i) == x)
		{
			set<int>& s1 = f(i-x);
			set<int>& s2 = f(x);
			for(set<int>::iterator it1=s1.begin(); it1!=s1.end(); it1++)
				for(set<int>::iterator it2=s2.begin(); it2!=s2.end(); it2++)
				{
					S[i].insert(*it1 + *it2);
					S[i].insert(*it1 - *it2);
					S[i].insert(*it2 - *it1);
					S[i].insert(*it1 * *it2);
					if(*it2 != 0)
						S[i].insert(*it1 / *it2);
					if(*it1 != 0)
						S[i].insert(*it2 / *it1);
				}
		}
	}
	return S[i];
}

int main()
{
	int a[4];
	N = 4;
	for(int i=0; i<N; i++)
	{
		cin>>a[i];
		S[1<<i].insert(a[i]);
	}
	int num = (1<<N) -1;
	f(num);
	int c = S[num].count(24);   //查询元素是否存在 
	cout<<"count: "<<c<<endl;
	return 0;
}*/

#include <iostream>
#include <set>
#include <string>
#include <cmath>
#include <cstdio>

#define N 4   //4张牌，可变
#define RES 24   //运算结果为24，可变
#define EPS 1e-6 

using namespace std;

struct Elem
{
	Elem(double r, string& i):res(r), info(i)
	{}
	Elem(double r, char* i):res(r), info(i)
	{}
	double res;   //运算出的数据
	string info;  //运算的过程
	bool operator<(const Elem& e)const
	{
		return res < e.res;   //在set的红黑树插入操作中需要用到比较操作 
	} 
}; 

int A[N];    //记录N个数据
//用二进制数来标示集合和子集的概念，0110标示集合包含第2,3个数
set<Elem> vset[1<<N];   //包含4个元素的集合共有16个子集0-15

set<Elem>& Fork(int m)
{
	//memo递归
	if(vset[m].size()) 
		return vset[m];
	
	for(int i=1; i<=m/2; i++)   //因为分别计算Fork(i)与Fork(m-i)，所以计算一半就行了
		if((i&m) == i)
		{
			set<Elem>& s1 = Fork(i);
			set<Elem>& s2 = Fork(m-i);
			//得到两个子集合的笛卡尔积，并对结果集合的元素对进行6种运算
			for(set<Elem>::iterator cit1 = s1.begin(); cit1 != s1.end(); cit1++)
				for(set<Elem>::iterator cit2 = s2.begin(); cit2 != s2.end(); cit2++) 
				{
					string str;
					str = "(" + cit1->info + "+" +cit2->info + ")";
					vset[m].insert(Elem(cit1->res + cit2->res,str));
					str = "(" + cit1->info + "-" +cit2->info + ")";
					vset[m].insert(Elem(cit1->res - cit2->res, str));
					str = "(" +cit2->info + "-" + cit1->info + ")";
					vset[m].insert(Elem(cit2->res - cit1->res, str));
					str = "(" + cit1->info + "*" +cit2->info + ")";
					vset[m].insert(Elem(cit1->res * cit2->res, str));
					if(abs(cit2->res) > EPS)
					{
						str = "(" +cit1->info + "/" +cit2->info + ")";
						vset[m].insert(Elem(cit1->res / cit2->res, str)); 
					} 
					if(abs(cit1->res) >EPS)
					{
						str = "(" + cit2->info + "/" +cit1->info + ")";
						vset[m].insert(Elem(cit2->res / cit1->res, str)); 
					} 
				} 
		} 
		return vset[m]; 
} 

int main()
{
	int i;
	for(i=0; i<N; i++)
		cin>>A[i];
		
	//递归的结束条件
	for(i=0; i<N; i++)
	{
		char str[10];
		sprintf(str, "%d", A[i]);
		vset[1<<i].insert(Elem(A[i], str)); 
	} 
	Fork((1<<N)-1);   //开始1111表示四个数
	
	//显示算出24点的运算过程
	for(set<Elem>::iterator it=vset[(1<<N)-1].begin(); it != vset[(1<<N)-1].end(); it++)
	{
		if(abs(it->res - RES) < EPS)
			cout<<it->info<<endl; 
	} 
	return 0; 
}



