#include <iostream>
using namespace std;
class CMeter
{
public:
	CMeter(int nPos=10)
	{
		m_nPos=nPos;
	}
	~CMeter() {}
	void StepIt()
	{
		m_nPos++;
	}
	int GetPos()
	{
		return m_nPos;
	}
protected:
	void SetPos(int nPos)
	{
		m_nPos=nPos;
	}
private:
	int m_nPos;
};
class CStick:public CMeter
{
	int m_nStickNum;
public:
	void DispStick();
	void SetStick(int nPos)
	{
		SetPos(nPos);
	}
};
void CStick::DispStick()
{
	m_nStickNum=GetPos();
	cout<<m_nStickNum<<' ';
}
int main()
{
	CMeter oMeter(20);
	CStick oStick;
	cout<<"CMeter:"<<oMeter.GetPos()<<",CStick:"<<oStick.GetPos()<<endl;
	oMeter.StepIt();
	cout<<"CMeter:"<<oMeter.GetPos()<<",CStick:"<<oStick.GetPos()<<endl;
	oStick.StepIt();
	cout<<"CMeter:"<<oMeter.GetPos()<<",CStick:"<<oStick.GetPos()<<endl;
	oStick.DispStick();
	oStick.StepIt();
	oStick.DispStick();
	return 0;
}