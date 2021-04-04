#include <iostream>
using namespace std;
int main()
{
	char s1[80],s2[80],s3[80];
	cout<<"请输入一个字符：";
	cout<<cin.get()<<endl;
	cin.get();//提取换行符
	cout<<"请输入一行字符串:";
	for(int i=0;i<80;i++)
	{
		cin.get(s1[i]);
		if(s1[i]=='\n')
		{
			s1[i]='\0';
			break;
		}
	}
	cout<<s1<<endl;
	cout<<"请输入一行字符串:";
	cin.get(s2,80);
	cout<<s2<<endl;
	cin.get();			//提取换行符
	cout<<"请输入一行字符串：";
	cin.getline(s3,80);
	cout<<s3<<endl;
	return 0;
}