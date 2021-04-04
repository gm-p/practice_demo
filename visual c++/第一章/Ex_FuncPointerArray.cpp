#include <iostream>
using namespace std;
void add(double x,double y)
{
	cout<<x<<"+"<<y<<"="<<x+y<<"\n";
}
void sub(double x,double y)
{
	cout<<x<<"-"<<y<<"="<<x-y<<"\n";
}
void mul(double x,double y)
{
	cout<<x<<"*"<<y<<"="<<x*y<<endl;
}
void div(double x,double y)
{
	cout<<x<<"/"<<y<<"="<<x/y<<endl;
}
void (*func[4])(double,double)={add,sub,mul,div};
int main()
{
	double x=3,y=7;
	char op;
	do
	{
		cout<<"+ ------ 相加\n"
			<<"- ------ 相减\n"
			<<"* ------ 相乘\n"
			<<"/ ------ 相除\n"
			<<"0 ------ 退出\n";
		cin>>op;
		switch(op)
		{
		case '+':func[0](x,y); break;
		case '-':func[1](x,y); break;
		case '*':func[2](x,y); break;
		case '/':func[3](x,y); break;
		case '0':return;
		}
	}while(1);
	//return 0;
}