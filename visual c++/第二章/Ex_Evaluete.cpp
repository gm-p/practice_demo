#include <iostream>
#include <cstring>
using namespace std;
class CName
{
public:
	CName(char *s)
	{
		name=new char[strlen(s)+1];
		strcpy(name,s);
	}
	~CName()
	{
		if(name)
		{
			delete []name;
			name=NULL;
		}
	}
	void print()
	{
		cout<<name<<endl;
	}
	CName& operator=(CName &a)//¸³ÖµÔËËã·ûÖØÔØ
	{
		if(name)
		{
			delete []name;
			name=NULL;
		}
		if(a.name)
		{
			name=new char[strlen(a.name)+1];
			strcpy(name,a.name);
		}
		return *this;
	}
private:
	char *name;
};
int main()
{
	CName d1("Key"),d2("Mouse");
	d1.print();
	d1=d2;
	d1.print();
	return 0;
}