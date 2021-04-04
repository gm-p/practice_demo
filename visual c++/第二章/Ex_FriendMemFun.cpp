#include <iostream>
using namespace std;
class CRect;
class CPoint
{
public:
	void Inflate(CRect &rc,int nOffset);
	CPoint(int x=0,int y=0)
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
};
class CRect
{
	friend void CPoint::Inflate(CRect &rc,int nOffset);
public:
	CRect(int x1=0,int y1=0,int x2=0,int y2=0)
	{
		xLeft=x1;
		xRight=x2;
		yTop=y1;
		yBottom=y2;
	}
	void Print()
	{
		cout<<"Rect("<<xLeft<<","<<yTop<<","<<xRight<<","<<yBottom<<")"<<endl;
	}
private:
	int xLeft,yTop,xRight,yBottom;
};
void CPoint::Inflate(CRect &rc,int nOffset)
{
	xPos+=nOffset;
	yPos+=nOffset;
	rc.xLeft+=nOffset;
	rc.xRight+=nOffset;
	rc.yTop+=nOffset;
	rc.yBottom+=nOffset;
}
int main()
{
	CPoint pt(10,20);
	CRect rc(0,0,100,80);
	pt.Print();
	rc.Print();
	pt.Inflate(rc,3);
	pt.Print();
	rc.Print();
	return 0;
}