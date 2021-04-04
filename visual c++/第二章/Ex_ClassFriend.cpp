#include <iostream>
using namespace std;
class CPoint
{
	friend class COther;
public:
	CPointer(int x=0,int y=0)
	{
		xPos=x;
		yPos=y;
	}
	void Print()
	{
		cout<<"Point("<<xPos<<","<<yPos<<")"<<endl;
	}
private:
	int xPos,yPos;
	void Inflate(int nOffset)
	{
		xPos+=nOffset;
		yPos+=nOffset;
	}
};
class COther
{
public:
	COther(int a=0,int b=0)
	{
		pt.xPos=a;
		pt.yPos=b;
	}
	void Display(void)
	{
		pt.Inflate(10);
		pt.Print();
	}
private:
	CPoint pt;
};
int main()
{
	COther one(12,18);
	one.Display();
	return 0;
}