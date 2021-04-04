#include <iostream>
using namespace std;
int main()
{
	int nTotal=0;
	for(int nNum=1;nNum<=50;nNum++)
		nTotal+=nNum;
	cout<<"The sum from 1 to 50 is:"<<nTotal<<"\n";
	return 0;
}