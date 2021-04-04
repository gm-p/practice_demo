#include <iostream.h>
#include <iomanip.h>
//using namespace std;
int main()
{
	int nNum=12345;
	double dNum=12345.6789;
	char *str[]={"This","is","a Test!"};
	cout<<setiosflags(ios::oct|ios::showbase|ios::showpos);
	cout<<nNum<<"\t"<<dNum<<endl;
	cout<<setiosflags(ios::hex|ios::scientific|ios::uppercase);
	cout<<nNum<<"\t"<<dNum<<endl;
	cout<<setfill('*');
	for(int i=0;i<3;i++)
		cout<<setw(12)<<str[i]<<"  ";
	cout<<endl;
	cout<<setiosflags(ios::left);
	for(i=0;i<3;i++)
		cout<<setw(12)<<str[i]<<"  ";
	cout<<endl;
	return 0;
}
/*#include <iostream>
using namespace std;
#include <iomanip>
int main()
{
	int nNum=12345;
	double dNum=12345.6789;
	cout<<setiosflags(ios::oct|ios::showbase|ios::showpos);
	cout<<setbase(8)<<nNum<<"\t"<<dNum<<endl;
	cout<<setiosflags(ios::hex|ios::scientific|ios::uppercase);
	cout<<setbase(16)<<nNum<<"\t"<<dNum<<endl;
	return 0;
}*/