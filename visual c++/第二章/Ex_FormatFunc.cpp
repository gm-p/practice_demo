#include <iostream.h>
//using namespace std;
int main()
{
	int nNum=12345;
	double dNum=12345.6789;
	char *str[]={"This","is","a Test!"};
	cout.setf(ios::oct|ios::showbase|ios::showpos);
	cout<<nNum<<"\t"<<dNum<<endl;
	cout.setf(ios::hex|ios::scientific|ios::uppercase);
	cout<<nNum<<"\t"<<dNum<<endl;
	cout.fill('*');
	for(int i=0;i<3;i++)
	{
		cout.width(12);
		cout<<str[i]<<"  ";
	}
	cout<<endl;
	cout.setf(ios::left);
	for(i=0;i<3;i++)
	{
		cout.width(12);
		cout<<str[i]<<"  ";
	}
	cout<<endl;
	return 0;
}
