//http://blog.csdn.net/yangtrees/article/details/8521005

//��Ŀ����N��ֳɶ��������Ӻ͵���ʽ��������е���ʽ 
//˼·���õݹ�ʵ�֣�ʹ��һ��list����ǰ׺���֣����ǰ׺�뵱ǰ����

#include <iostream>
#include <list>
using namespace std;

void print_list(list<int>::iterator iter1, list<int>::iterator iter2)  //���ǰ׺���� 
{
	for(list<int>::iterator iter=iter1; iter!=iter2; iter++)
		cout<<*iter<<" "; 
} 

void f(int n, list<int>& lst, int start)  //nΪ��ǰ���֣�iΪ���λ�� 
{
	if(n == 1)
	{
		print_list(lst.begin(), lst.end());
		cout<<1<<endl; 
	} 
	else
	{
		for(int i=start; i<=n/2; i++)    //��Ϊ1+2...��2+1...Ч��һ������ֻ��n/2 
		{
			lst.push_back(i);
			f(n-i, lst, i);
			lst.pop_back(); 
		} 
	
		print_list(lst.begin(), lst.end());  //���ǰ׺ 
		cout<<n<<endl;   //�����ǰ���� 
	} 
} 

int main()
{
	list<int> listT;
	f(9, listT, 1);
	return 0; 
} 
