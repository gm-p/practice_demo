#include <iostream>
using namespace std;
int main()
{
	int i,s;
	char buf[80];
	cout<<"输入一个整数：";
	cin>>i;
	s=cin.rdstate();
	cout<<"流状态为："<<hex<<s<<endl;
	while(s)
	{
		cin.clear();
		cin.getline(buf,80);
		cout<<"非法输入，重新输入一个整数：";
		cin>>i;
		s=cin.rdstate();
	}
	return 0;
}