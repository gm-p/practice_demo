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
	os<<endl<<"学生信息如下："<<endl;
	os<<"姓名："<<stu.strName<<endl;
	os<<"学号："<<stu.strID<<endl;
	os<<"成绩："<<stu.fScore[0]<<",\t"<<stu.fScore[1]<<",\t"<<stu.fScore[2]<<endl;
	return os;
}
istream& operator>>(istream& is,CStudent &stu)
{
	cout<<"请输入学生信息"<<endl;
	cout<<"姓名：";  is>>stu.strName;
	cout<<"学号：";  is>>stu.strID;
	cout<<"三门成绩：";  is>>stu.fScore[0]>>stu.fScore[1]>>stu.fScore[2];
	return is;
}
int main()
{
	CStudent one;
	cin>>one;
	cout<<one;
	return 0;
}