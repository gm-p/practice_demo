#include <iostream>
using namespace std;
int main()
{
	int a[]={5,8,7,6,2,7,3};
	int y,*p=&a[1];
	y=(*--p)++;
	cout<<y<<endl;
	return 0;
}