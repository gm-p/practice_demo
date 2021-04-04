//http://blog.csdn.net/yangtrees/article/details/8521005

//题目：将N拆分成多个整数相加和的形式，求出所有的形式 
//思路：用递归实现：使用一个list保存前缀数字，输出前缀与当前数字

#include <iostream>
#include <list>
using namespace std;

void print_list(list<int>::iterator iter1, list<int>::iterator iter2)  //输出前缀数字 
{
	for(list<int>::iterator iter=iter1; iter!=iter2; iter++)
		cout<<*iter<<" "; 
} 

void f(int n, list<int>& lst, int start)  //n为当前数字，i为拆分位置 
{
	if(n == 1)
	{
		print_list(lst.begin(), lst.end());
		cout<<1<<endl; 
	} 
	else
	{
		for(int i=start; i<=n/2; i++)    //因为1+2...与2+1...效果一样，故只到n/2 
		{
			lst.push_back(i);
			f(n-i, lst, i);
			lst.pop_back(); 
		} 
	
		print_list(lst.begin(), lst.end());  //输出前缀 
		cout<<n<<endl;   //输出当前数字 
	} 
} 

int main()
{
	list<int> listT;
	f(9, listT, 1);
	return 0; 
} 
