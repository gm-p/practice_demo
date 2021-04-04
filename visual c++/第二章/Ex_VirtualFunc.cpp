#include <iostream>
using namespace std;
class CShape
{
public:
	virtual float area()
	{
		return 0.0;
	}
};
class CTriangle:public CShape
{
public:
	CTriangle(float h,float w)
	{
		H=h;
		W=w;
	}
	float area()
	{
		return (float)(H*W*0.5);
	}
private:
	float H,W;
};
class CCircle:public CShape
{
public:
	CCircle(float r)
	{
		R=r;
	}
	float area()
	{
		return (float)(3.14159265*R*R);
	}
private:
	float R;
};
int main()
{
	CShape *s[2];
	s[0]=new CTriangle(3,4);
	cout<<s[0]->area()<<endl;
	s[1]=new CCircle(5);
	cout<<s[1]->area()<<endl;
	return 0;
}