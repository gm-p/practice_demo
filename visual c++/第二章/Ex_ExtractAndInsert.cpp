#include <iostream>
using namespace std;
class CStudent
{
public:
	friend ostream& operator<<(ostream& os,CStudent &stu);
	friend istream& operator>>(istream& is,CStudent &stu);
private:
	char strName[10];
	char strID[10];
	float fScore[3];
};
ostream& operator<<(ostream& os,CStudent &stu)
{
	os<<endl<<"ѧ����Ϣ���£�"<<endl;
	os<<"������"<<stu.strName<<endl;
	os<<"ѧ�ţ�"<<stu.strID<<endl;
	os<<"�ɼ���"<<stu.fScore[0]<<",\t"<<stu.fScore[1]<<",\t"<<stu.fScore[2]<<endl;
	return os;
}
istream& operator>>(istream& is,CStudent &stu)
{
	cout<<"������ѧ����Ϣ"<<endl;
	cout<<"������";  is>>stu.strName;
	cout<<"ѧ�ţ�";  is>>stu.strID;
	cout<<"���ųɼ���";  is>>stu.fScore[0]>>stu.fScore[1]>>stu.fScore[2];
	return is;
}
int main()
{
	CStudent one;
	cin>>one;
	cout<<one;
	return 0;
}