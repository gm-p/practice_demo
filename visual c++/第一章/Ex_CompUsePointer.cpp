#include <iostream>
using namespace std;
int main()
{
	int *p1,*p2,*p,a,b;
	cout<<"��������������";
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
	cout<<"����ֵ�ǣ�"<<*p1<<",��С��ֵ�ǣ�"<<*p2<<"\n";
	return 0;
}