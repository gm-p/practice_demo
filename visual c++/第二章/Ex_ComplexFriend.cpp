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
	friend CComplex operator+(double r,CComplex &c);
	friend CComplex operator-(CComplex &c);
	void operator+=(CComplex &c);
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
CComplex operator+(double r,CComplex &c)
{
	CComplex temp;
	temp.realPart=r+c.realPart;
	temp.imagePart=c.imagePart;
	return temp;
}
CComplex operator-(CComplex &c)
{
	return CComplex(-c.realPart,-c.imagePart);
}
void CComplex::operator+=(CComplex &c)
{
	realPart+=c.realPart;
	imagePart+=c.imagePart;
}
int main()
{
	CComplex c1(12,20),c2(30,70),c;
	c=c1+c2;
	c.print();
	c=c1+20;
	c.print();
	c=20+c2;
	c.print();
	c2+=c1;
	c2.print();
	c1=-c1;
	c1.print();
	return 0;
}
