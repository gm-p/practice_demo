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
		n = n & (n-1);    //清除n最右边的1 
	}
	return count;
}

int main()
{
	int m, num;
	cin>>m;
	cout<<bitset<14>(m)<<endl;  //输出14位二进制数m
	num = fun(m);
	cout<<num<<endl;
	return 0; 
}
