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
	cout<<"姓名："<<(*p).name<<endl;
	cout<<"性别："<<(*p).sex<<endl;
	cout<<"年龄："<<(*p).age<<endl;
	cout<<"体重（kg）:"<<(*p).weight<<endl;
	return 0;
}