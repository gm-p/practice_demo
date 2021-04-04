#include <iostream>
using namespace std;
int main()
{
	int nNum=1,nTotal=0;
	do
	{
		nTotal+=nNum;
		nNum++;
	}while(nNum<=50);
	cout<<"The sum from 1 to 50 is:"<<nTotal<<"\n";
	return 0;
}