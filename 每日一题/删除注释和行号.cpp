
//��Ŀ1��ɾ��ע��
//ɾ��C++�����е�ע�Ͳ���
//1. //Annotation
//2. /*Annotation*/ 

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

char* filename = "D:/ÿ��һ��/ɾ��ע�ͺ��к�.cpp";

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
	while(inf.get(c1))   //��ʹ��inf>>c1,���޷���ȡ���л�ո� 
	{
		if(c1 == '/')
		{
			inf.get(c2);
			if(c2 == '/')   //���1����//�� 
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
			/*/���2����ÿ��ֻ����һλ/*/   
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
		else    //�������else�ᵼ�½�/'���/'/������c1,c2,c1�� 
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

//��Ŀ2��ɾ���к�
//˼·��ʹ��getline���ÿһ�У�Ȼ�����һ��Ԫ���Ƿ�Ϊ���֣�����������Ǩ��һλ 


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
	ifstream infile("D:/ÿ��һ��/in.txt");
	ofstream outfile("D:/ÿ��һ��/out.txt");
	string str;
	while(getline(infile, str)) 
	{
		CheckAndMove(str);
		cout<<str<<endl;
		outfile<<str<<endl; 
	} 
	return 0;
} 
