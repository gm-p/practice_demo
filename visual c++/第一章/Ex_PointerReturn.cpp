#include <iostream>
using namespace std;
char* flip(char *str)
{
	char *p1,*p2,ch;
	p1=p2=str;
	while(*p2!='\0')
		p2++;
	p2--;
	while(p1<p2)
	{
		ch=*p2;
		*p2=*p1;
		*p1=ch;
		p1++;
		p2--;
	}
	return str;
}
int main()
{
	char str[]="ABCDEFGH";
	cout<<flip(str)<<"\n";
	return 0;
}