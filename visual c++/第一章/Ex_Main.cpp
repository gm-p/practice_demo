#include <iostream>
using namespace std;
int main(int argc,char *argv[])
{
	cout<<"��������������:"<<argv[0]<<endl;
	if(argc<=1)
		cout<<"û�в���!";
	else
	{
		int nCount=1;
		while(nCount<argc)
		{
			cout<<"��"<<nCount<<"��������:"<<argv[nCount]<<"\n";
			nCount++;
		}
	}
	return 0;
}