#include <iostream>
using namespace std;
double area;
double &CalArea(double r)
{
	area=3.141593*r*r;
	return area;
}
int main()
{
	double c=CalArea(5.0);
	double &d=CalArea(10.0);
	cout<<c<<endl;
	cout<<d<<endl;
	return 0;
}