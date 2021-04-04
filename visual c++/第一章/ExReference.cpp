#include <iostream>
using namespace std;
int main()
{
	int a;
	int &ra=a;
	a=5;
	cout<<"a="<<a<<"\n";
	cout<<"ra="<<ra<<endl;
	cout<<"a的地址是："<<&a<<endl;
	cout<<"ra的地址是:"<<&ra<<endl;
	int b=8;
	ra=b;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	cout<<"ra="<<ra<<endl;
	cout<<"a的地址是："<<&a<<endl;
	cout<<"b的地址是:"<<&b<<endl;
	cout<<"ra的地址是："<<&ra<<endl;
	return 0;
}