#include <iostream>
using namespace std;
class CShape
{
public:
	virtual float area()=0;  //将area定义成纯虚函数
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
	CShape *pShape;
	CTriangle tri(3,4);
	cout<<tri.area()<<endl;
	pShape=&tri;
	cout<<pShape->area()<<endl;
	CCircle cir(5);
	cout<<cir.area()<<endl;
	pShape=&cir;
	cout<<pShape->area()<<endl;
	return 0;
}