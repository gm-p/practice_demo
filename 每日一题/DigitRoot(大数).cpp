#include <iostream>
#include <cstring>
using namespace std;

int root(int n)
{
	int sum=0;
	if(n < 10)
		return n;
	while(n)
	{
		sum += n%10;
		n /= 10;
	}
	if(sum < 10)
		return sum;
	else
		return root(sum);
}

int main()
{
	
	char str[2000];   //这里主要考察大数据，可能有上千位数字，所以应该把输入当成字符串处理 
	while(cin>>str)
	{
		int a=0;
		for(int i=0; i<strlen(str); i++)
			a += str[i] - '0';
		if(a == 0)
			break;
		cout<<root(a)<<endl;
	}
	return 0;
}
