#include <iostream>
using namespace std;
int main()
{
	char data[80];
	cout<<"ÇëÊäÈë£º"<<endl;
	cin.read(data,80);
	data[cin.gcount()]='\0';
	cout<<endl<<data<<endl;
	return 0;
}