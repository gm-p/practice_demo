#include <iostream>
using namespace std;
class COne
{
public:
	void print(const int *p,int n)
	{
		cout<<"{"<<*p;
		for(int i=1;i<n;i++)
			cout<<","<<*(p+i);
		cout<<"}"<<endl;
	}
};
int main()
{
	int array[6]={1,2,3,4,5,6};
	COne one;
	one.print(array,6);
	return 0;
}