#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	fstream file1;
	file1.open("Ex_DataFile.txt",ios::in);
	if(!file1)
	{
		cout<<"Ex_DataFile.txt不能打开！\n";
		//return;
	}
	fstream file2;
	file2.open("Ex_DataFileBak.txt",ios::out|ios::trunc);
	if(!file2)
	{
		cout<<"Ex_DataFileBak.txt不能创建！\n";
		file1.close();
		//return ;
	}
	char ch;
	while(!file1.eof())
	{
		file1.read(&ch,1);
		cout<<ch;
		file2.write(&ch,1);
	}
	file2.close();
	file1.close();
	return 0;
}
