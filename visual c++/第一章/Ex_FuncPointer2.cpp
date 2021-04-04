#include <iostream>
using namespace std;
double add(double x,double y)
{
	return x+y;
}
double mul(double x,double y)
{
	return x*y;
}
void op(double(*func)(double,double),double x,double y)
{
	cout<<"x="<<x<<",y="<<y<<",result="<<func(x,y)<<"\n";
}
int main()
{
	cout<<"使用加法函数：";
	op(add,3,7);
	cout<<"使用乘法函数：";
	op(mul,3,7);
	return 0;
}