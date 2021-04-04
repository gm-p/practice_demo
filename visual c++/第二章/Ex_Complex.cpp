#include <iostream>
using namespace std;
class CComplex
{
public:
	CComplex(double r=0,double i=0)
	{
		realPart=r;
		imagePart=i;
	}
	void print()
	{
		cout<<"Êµ²¿="<<realPart<<"£¬Ðé²¿="<<imagePart<<endl;
	}
	CComplex operator+(CComplex &c);
	CComplex operator+(double r);
private:
	double realPart;
	double imagePart;
};
CComplex CComplex::operator+(CComplex &c)
{
	CComplex temp;
	temp.realPart=realPart+c.realPart;
	temp.imagePart=imagePart+c.imagePart;
	return temp;
}
CComplex CComplex::operator+(double r)
{
	CComplex temp;
	temp.realPart=realPart+r;
	temp.imagePart=imagePart;
	return temp;
}
int main()
{
	CComplex c1(12,20),c2(50,70),c;
	c=c1+c2;
	c.print();
	c=c1+20;
	c.print();
	return 0;
}