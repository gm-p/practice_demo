#include <iostream>
using namespace std;
class COne
{
public:
	COne(int a,int b)
	{
		x=a;
		y=b;
	}
	void print();
	void print()const;
private:
	int x,y;
};
void COne::print()
{
	cout<<x<<","<<y<<endl;
}
void COne::print()const
{
	cout<<"ʹ�ó���Ա������"<<x<<","<<y<<endl;
}
int main()
{
	COne one(5,4);
	one.print();
	const COne two(20,52);
	two.print();
	return 0;
}