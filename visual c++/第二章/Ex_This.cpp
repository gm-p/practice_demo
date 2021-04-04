#include <iostream>
using namespace std;
class COne
{
public:
	COne()
	{
		x=y=0;
	}
	COne(int a,int b)
	{
		x=a;
		y=b;
	}
	void copy(COne &a);
	void print()
	{
		cout<<x<<","<<y<<endl;
	}
private:
	int x,y;
};
void COne::copy(COne &a)
{
	if(this==&a)
		return;
	*this=a;
}
int main()
{
	COne one,two(3,4);
	one.print();
	one.copy(two);
	one.print();
	return 0;
}