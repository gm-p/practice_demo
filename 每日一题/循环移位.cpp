//1.���ڲ�������ȫ������ 
/*
#include <iostream>
#include <string>

using namespace std;

string s = "I am Jack Chen";

void swap(int left, int right)
{
	char tmp;
	while(left < right)
	{
		tmp = s[right];
		s[right] = s[left];
		s[left] = tmp;
		left++;
		right--;
	}
}

int main()
{
	int length = s.size();
	int k=0;
	int low=0, high=0;
	while(1)
	{
		if(s[k] == ' ' || k == length-1)
		{
			if(s[k] == ' ')
				high = k-1;  //���������ո�����ǰ��һλ 
			else
				high = k; //���ǵ���ĩβ��ֱ�Ӳ���
			swap(low, high);
			low = k+1; 
		}
		if(k==length-1)
			break;
		k++; 
	}
	swap(0, length-1);
	cout<<s<<endl;
	return 0; 
}*/

//2.ʹ�÷��������: reverse_iterator

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void reverseWord()
{
	vector<string> vec;
	string word;
	while(cin>>word)
		vec.push_back(word);
	vector<string>::reverse_iterator it;   //ʹ�÷�����������
	for(it=vec.rbegin(); it!=vec.rend(); it++)
		cout<<*it<<" ";
	cout<<endl; 
}

int main()
{
	reverseWord();
	return 0; 
} 
