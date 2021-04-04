#include <iostream>
using namespace std;
 
class Point
{
	private:
		int x,y;
	public:
		Point(int i = 0, int j = 0);
		friend Point operator++(Point &ob);
		Point operator+(Point &ob);
		void Print();
 
};
 
Point::Point(int i, int j)
{
	x = i;
	y = j;
}
 
void Point::Print()
{
	cout << "(" << x << "," << y << ")" <<endl;
}
 
Point Point::operator+(Point &ob)
{
	Point p;
	p.x = x + ob.x;
	p.y = y + ob.y;
	return p;
}

Point operator++(Point &ob)
{
	++ob.x;
	++ob.y;
	return ob;
}
 
int main()
{
	Point ob1(1, 2), ob2, ob3;
	cout << "ob1:" <<endl;
	ob1.Print();
	ob2 = ++ob1;
	cout << "++ob1: " <<endl;
	ob1.Print();
	cout << "ob2:" <<endl;
	ob2.Print();
	ob3 = ob1 + ob2;
	ob3.Print();
	return 0;

}
