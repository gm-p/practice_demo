#include <iostream>
using namespace std;
class CCounter
{
public:
	CCounter(int n=0)
	{
		unCount=n;
	}
	CCounter& operator++();//前缀++运算符重载声明
	friend CCounter operator++(CCounter &one,int);//后缀++运算符友元重载声明
	void print()
	{
		cout<<unCount<<endl;
	}
private:
	unsigned unCount;
};
CCounter& CCounter::operator++()
{
	unCount++;
	return *this;
}
CCounter operator++(CCounter &one,int)
{
	CCounter temp=one;
	one.unCount++;
	return temp;
}
int main()
{
	CCounter d1(8),d2;
	d2=d1++;
	d1.print();
	d2.print();
	d2=++d1;
	d1.print();
	d2.print();
	++++d1;
	d1.print();
	return 0;
}