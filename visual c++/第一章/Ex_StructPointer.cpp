#include <iostream>
#include <cstring>
using namespace std;
struct PERSON
{
	int age;
	char sex;
	float weight;
	char name[25];
};
int main()
{
	struct PERSON one;
	struct PERSON *p;
	p=&one;
	p->age=32;
	p->sex='M';
	p->weight=(float)80.2;
	strcpy(p->name,"LiMing");
	cout<<"������"<<(*p).name<<endl;
	cout<<"�Ա�"<<(*p).sex<<endl;
	cout<<"���䣺"<<(*p).age<<endl;
	cout<<"���أ�kg��:"<<(*p).weight<<endl;
	return 0;
}