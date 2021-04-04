//���� 
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
	int c = S[num].count(24);   //��ѯԪ���Ƿ���� 
	cout<<"count: "<<c<<endl;
	return 0;
}*/

#include <iostream>
#include <set>
#include <string>
#include <cmath>
#include <cstdio>

#define N 4   //4���ƣ��ɱ�
#define RES 24   //������Ϊ24���ɱ�
#define EPS 1e-6 

using namespace std;

struct Elem
{
	Elem(double r, string& i):res(r), info(i)
	{}
	Elem(double r, char* i):res(r), info(i)
	{}
	double res;   //�����������
	string info;  //����Ĺ���
	bool operator<(const Elem& e)const
	{
		return res < e.res;   //��set�ĺ���������������Ҫ�õ��Ƚϲ��� 
	} 
}; 

int A[N];    //��¼N������
//�ö�����������ʾ���Ϻ��Ӽ��ĸ��0110��ʾ���ϰ�����2,3����
set<Elem> vset[1<<N];   //����4��Ԫ�صļ��Ϲ���16���Ӽ�0-15

set<Elem>& Fork(int m)
{
	//memo�ݹ�
	if(vset[m].size()) 
		return vset[m];
	
	for(int i=1; i<=m/2; i++)   //��Ϊ�ֱ����Fork(i)��Fork(m-i)�����Լ���һ�������
		if((i&m) == i)
		{
			set<Elem>& s1 = Fork(i);
			set<Elem>& s2 = Fork(m-i);
			//�õ������Ӽ��ϵĵѿ����������Խ�����ϵ�Ԫ�ضԽ���6������
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
		
	//�ݹ�Ľ�������
	for(i=0; i<N; i++)
	{
		char str[10];
		sprintf(str, "%d", A[i]);
		vset[1<<i].insert(Elem(A[i], str)); 
	} 
	Fork((1<<N)-1);   //��ʼ1111��ʾ�ĸ���
	
	//��ʾ���24����������
	for(set<Elem>::iterator it=vset[(1<<N)-1].begin(); it != vset[(1<<N)-1].end(); it++)
	{
		if(abs(it->res - RES) < EPS)
			cout<<it->info<<endl; 
	} 
	return 0; 
}



