#include <iostream>
#include <cstring>
using namespace std;
class CAnimal
{
public:
	CAnimal(char *pName="noname");
	~CAnimal();
	void setName(char *pName)
	{
		strncpy(name,pName,sizeof(name));
	}
	char* getName(void)
	{
		return name;
	}
private:
	char name[20];
};
CAnimal::CAnimal(char *pName)
{
	setName(pName);
	cout<<"����CAnimal�Ĺ��캯����"<<endl;
}
CAnimal::~CAnimal()
{
	cout<<"����CAnimal������������"<<endl;
}
class CCat:public CAnimal
{
public:
	CCat()
	{
		cout<<"����CCat�Ĺ��캯����"<<endl;
	}
	~CCat()
	{
		cout<<"����CCat������������"<<endl;
	}
	void DispName()
	{
		cout<<"è�������ǣ�"<<getName()<<endl;
	}
};
int main()
{
	CCat cat;
	cat.DispName();
	cat.setName("Snoopy");
	cat.DispName();
	return 0;
}
