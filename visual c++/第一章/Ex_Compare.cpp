#include <iostream>
using namespace std;
int main()
{
	int nNum1,nNum2;
	cout<<"Please input two integer numbers:";
	cin>>nNum1>>nNum2;
	if(nNum1!=nNum2)
		if(nNum1>nNum2)
			cout<<nNum1<<">"<<nNum2<<endl;
		else
			cout<<nNum1<<"<"<<nNum2<<endl;
	else
		cout<<nNum1<<"="<<nNum2<<endl;
	return 0;
}