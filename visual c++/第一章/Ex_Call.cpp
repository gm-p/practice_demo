#include <iostream>
using namespace std;
void printline(char ch,int n)
{
	for(int i=0;i<n;i++)
		cout<<ch;
	cout<<endl;
}
int main()
{
	int row=5;
	for(int i=0;i<row;i++)
		printline('*',i+1);
	return 0;
}