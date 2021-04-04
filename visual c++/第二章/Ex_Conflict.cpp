#include <iostream>
using namespace std;
class A
{
public:
	int x;
	A(int a=0)
	{
		x=a;
	}
};
class B1:public A
{
public:
	int y1;
	B1(int a=0,int b=0):A(b)
	{
		y1=a;
	}
};
class B2:public A
{
public:
	int y2;
	B2(int a=0,int b=0):A(b)
	{
		y2=a;
	}
};
class C:public B1,public B2
{
public:
	int z;
	C(int a,int b,int d,int e,int m):B1(a,b),B2(d,e)
	{
		z=m;
	}
	void print()
	{
		//cout<<"x="<<x<<endl;			//二义性 编译出错
		cout<<"B1::x="<<B1::x<<endl;
		cout<<"B2::x="<<B2::x<<endl;
		cout<<"y1="<<y1<<",y2="<<y2<<endl;
		cout<<"z="<<z<<endl;
	}
};
int main()
{
	C c1(100,200,300,400,500);
	c1.print();
	return 0;
}