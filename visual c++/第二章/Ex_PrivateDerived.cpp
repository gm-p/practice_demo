#include <iostream>
using namespace std;
class CMeter
{
public:
	CMeter(int nPos=10)
	{
		m_nPos=nPos;
	}
	~CMeter() { }
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
class CStick:private CMeter
{
	int m_nStickNum;
public:
	void DispStick();
	void SetStick(int nPos)
	{
		SetPos(nPos);
	}
	int GetStick()
	{
		return GetPos();
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
	cout<<"CMeter:"<<oMeter.GetPos()<<",CStick:"<<oStick.GetStick()<<endl;
	oMeter.StepIt();
	cout<<"CMeter:"<<oMeter.GetPos()<<",CStick:"<<oStick.GetStick()<<endl;
	oStick.DispStick();
	return 0;
}