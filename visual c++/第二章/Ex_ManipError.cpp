#include <iostream>
using namespace std;
int main()
{
	int i,s;
	char buf[80];
	cout<<"����һ��������";
	cin>>i;
	s=cin.rdstate();
	cout<<"��״̬Ϊ��"<<hex<<s<<endl;
	while(s)
	{
		cin.clear();
		cin.getline(buf,80);
		cout<<"�Ƿ����룬��������һ��������";
		cin>>i;
		s=cin.rdstate();
	}
	return 0;
}