#include <iostream>
using namespace std;
class CPoint
{
	friend CPoint Inflate(CPoint &pt,int nOffset);
public:
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
CPoint Inflate(CPoint &pt,int nOffset)
{
	pt.xPos+=nOffset;
	pt.yPos+=nOffset;
	return pt;
}
int main()
{
	CPoint pt(10,20);
	pt.Print();
	Inflate(pt,3);
	pt.Print();
	return 0;
}