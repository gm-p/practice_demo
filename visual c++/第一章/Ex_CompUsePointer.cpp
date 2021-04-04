#include <iostream>
using namespace std;
int main()
{
	int *p1,*p2,*p,a,b;
	cout<<"输入两个整数：";
	cin>>a>>b;
	p1=&a;
	p2=&b;
	if(a<b)
	{
		p=p1;
		p1=p2;
		p2=p;
	}
	cout<<"a= "<<a<<", b= "<<b<<endl;
	cout<<"最大的值是："<<*p1<<",最小的值是："<<*p2<<"\n";
	return 0;
}