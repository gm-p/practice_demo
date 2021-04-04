#include <iostream>
using namespace std;
struct PERSON
{
	int age;
	float weight;
	char name[25];
};
void print(PERSON one)
{
	cout<<one.name<<"\t"
		<<one.age<<"\t"
		<<one.weight<<endl;
}
PERSON getperson()
{
	PERSON temp;
	cout<<"请输入姓名、年龄和体重：";
	cin>>temp.name>>temp.age>>temp.weight;
	return temp;
}
int main()
{
	PERSON one=getperson();
	print(one);
	return 0;
}
