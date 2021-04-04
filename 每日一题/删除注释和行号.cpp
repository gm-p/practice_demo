
//题目1：删除注释
//删除C++代码中的注释部分
//1. //Annotation
//2. /*Annotation*/ 

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

char* filename = "D:/每日一题/删除注释和行号.cpp";

int main()
{
	ifstream inf;
	char c1, c2, tmp;
	tmp = '\0';
	inf.open(filename);
	if(!inf)
	{
		cout<<"Can not open file!"<<endl;
		return -1; 
	} 
	while(inf.get(c1))   //若使用inf>>c1,则无法读取换行或空格 
	{
		if(c1 == '/')
		{
			inf.get(c2);
			if(c2 == '/')   //情况1：‘//’ 
			{
				while(inf.get(c1))
				{
					if(c1 == '\n')
					{
						cout<<"\n"; 
						break; 
				    }
				} 
				//continue;
			} 
			/*/情况2：需每次只后移一位/*/   
			else if(c2 == '*')
			{
				while(inf.get(c1))
				{
					if(tmp == '*' && c1 == '/')
					   break;
					tmp = c1; 
				} 
				//continue;
			} 
			else
				cout<<c1<<c2;
		} //endif
		else    //如果不加else会导致将/'变成/'/（即：c1,c2,c1） 
			cout<<c1;
	} 
	inf.close();
	
	/***test***/
  //  char tempC;
  //  inf.open(filename);
  //  while(inf.get(tmpC))
  //     if(tmpC == '/')
  //		cout<<tmpC;
  //*****   inf.close(); 
	return 0; 
}

//题目2：删除行号
//思路：使用getline获得每一行，然后检查第一个元素是否为数字，若是则整体迁移一位 


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void moveOne(string& str)
{
	int length = str.length();
	for(int i=1; i<length; i++)
		 str[i-1] = str[i];
	str[length-1] = '\0'; 
} 


void CheckAndMove(string& str)
{
	while(str.size() > 0 && '0' <= str[0] && str[0] <= '9')
	{
		moveOne(str); 
	} 
} 

int main()
{
	ifstream infile("D:/每日一题/in.txt");
	ofstream outfile("D:/每日一题/out.txt");
	string str;
	while(getline(infile, str)) 
	{
		CheckAndMove(str);
		cout<<str<<endl;
		outfile<<str<<endl; 
	} 
	return 0;
} 
