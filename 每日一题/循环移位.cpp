//1.先内部逆序，再全部逆序 
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
				high = k-1;  //若是遇见空格则往前退一位 
			else
				high = k; //若是到达末尾，直接操作
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

//2.使用反向迭代器: reverse_iterator

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
	vector<string>::reverse_iterator it;   //使用反向迭代器输出
	for(it=vec.rbegin(); it!=vec.rend(); it++)
		cout<<*it<<" ";
	cout<<endl; 
}

int main()
{
	reverseWord();
	return 0; 
} 
