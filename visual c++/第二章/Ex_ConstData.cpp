#include <iostream>
using namespace std;
class COne
{
public:
	COne(int a):x(a),r(x)
	{	}
	void print();
	const int &r;
private:
	const int x;
	static const int y;
};
const int COne::y=10;
void COne::print()
{
	cout<<"x="<<x<<",y="<<y<<",r="<<r<<endl;
}
int main()
{
	COne one(100);
	one.print();
	return 0;
}