#include <iostream>
using namespace std;
int main()
{
	char s1[80],s2[80],s3[80];
	cout<<"������һ���ַ���";
	cout<<cin.get()<<endl;
	cin.get();//��ȡ���з�
	cout<<"������һ���ַ���:";
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
	cout<<"������һ���ַ���:";
	cin.get(s2,80);
	cout<<s2<<endl;
	cin.get();			//��ȡ���з�
	cout<<"������һ���ַ�����";
	cin.getline(s3,80);
	cout<<s3<<endl;
	return 0;
}