#include <iostream>
#include <cstring>
using namespace std;
union PERSON
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
int main()
{
	PERSON	all={33};
	print(all);
	all.weight=80;
	print(all);
	strcpy(all.name,"ding");
	print(all);
	return 0;
}