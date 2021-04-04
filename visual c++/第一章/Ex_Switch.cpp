#include <iostream>
using namespace std;
int main()
{
	char chGrade;
	cout<<"Please input a char(A~E):";
	cin>>chGrade;
	switch(chGrade)
	{
	    case 'A':
	    case 'a':cout<<"90-100"<<endl;
			     break;
	    case 'B':
		case 'b':cout<<"80-89"<<endl;
				 break;
		case 'C':
		case 'c':cout<<"70-79"<<endl;
				 break;
		case 'D':
		case 'd':cout<<"60-69"<<endl;
			     break;
		case 'E':
		case 'e':cout<<"<60"<<endl;
			     break;
		default :cout<<"error!"<<endl;
	}
	return 0;
}