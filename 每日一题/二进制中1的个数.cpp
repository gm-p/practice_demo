//http://blog.csdn.net/yangtrees/article/details/8210783

#include <iostream>
#include <bitset>

using namespace std;

int fun(int n)
{
	int count=0;
	while(n)
	{
		count++;
		n = n & (n-1);    //���n���ұߵ�1 
	}
	return count;
}

int main()
{
	int m, num;
	cin>>m;
	cout<<bitset<14>(m)<<endl;  //���14λ��������m
	num = fun(m);
	cout<<num<<endl;
	return 0; 
}
