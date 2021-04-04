#include <iostream>
using namespace std;
void swap(float x,float y)
{
	float temp;
	temp=x;
	x=y;
	y=temp;
	cout<<"x="<<x<<",y="<<y<<"\n";
}
int main()
{
	float a=20,b=40;
	cout<<"a="<<a<<",b="<<b<<"\n";
	swap(a,b);
	cout<<"a="<<a<<",b="<<b<<"\n";
	return 0;
}