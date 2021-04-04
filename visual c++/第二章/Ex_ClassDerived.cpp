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
	cout<<"调用CAnimal的构造函数！"<<endl;
}
CAnimal::~CAnimal()
{
	cout<<"调用CAnimal的析构函数！"<<endl;
}
class CCat:public CAnimal
{
public:
	CCat()
	{
		cout<<"调用CCat的构造函数！"<<endl;
	}
	~CCat()
	{
		cout<<"调用CCat的析构函数！"<<endl;
	}
	void DispName()
	{
		cout<<"猫的名字是："<<getName()<<endl;
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
