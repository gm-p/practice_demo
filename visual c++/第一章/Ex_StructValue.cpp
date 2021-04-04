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
PERSON all[4]={ {20,60,"Zhang"},
				{28,50,"Fang"},
				{33,78,"Ding"},
				{19,65,"Chen"}};
int main()
{
	for(int i=0;i<4;i++)
		print(all[i]);
	return 0;
}