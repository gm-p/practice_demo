#include <iostream>
using namespace std;
int main()
{
	int a;
	int &ra=a;
	a=5;
	cout<<"a="<<a<<"\n";
	cout<<"ra="<<ra<<endl;
	cout<<"a�ĵ�ַ�ǣ�"<<&a<<endl;
	cout<<"ra�ĵ�ַ��:"<<&ra<<endl;
	int b=8;
	ra=b;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	cout<<"ra="<<ra<<endl;
	cout<<"a�ĵ�ַ�ǣ�"<<&a<<endl;
	cout<<"b�ĵ�ַ��:"<<&b<<endl;
	cout<<"ra�ĵ�ַ�ǣ�"<<&ra<<endl;
	return 0;
}