#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <string.h>
//using namespace std;
class CStudent
{
public:
	CStudent(char* name,char* id,float score=0);
	void print();
	friend ostream& operator<<(ostream &os,CStudent &stu);
	friend istream& operator>>(istream &is,CStudent &stu);
private:
	char strName[10];
	char strID[10];
	float fScore;
};
CStudent::CStudent(char* name,char* id,float score)
{
	strncpy(strName,name,10);
	strncpy(strID,id,10);
	fScore=score;
}
void CStudent::print()
{
	cout<<endl<<"学生信息如下:"<<endl;
	cout<<"姓名："<<strName<<endl;
	cout<<"学号："<<strID<<endl;
	cout<<"成绩："<<fScore<<endl;
}
ostream& operator<<(ostream &os,CStudent &stu)
{
	os.write(stu.strName,10);
	os.write(stu.strID,10);
	os.write((char*)&stu.fScore,4);
	return os;
}
istream& operator>>(istream &is,CStudent &stu)
{
	char name[10];
	char id[10];
	is.read(name,10);
	is.read(id,10);
	is.read((char*)&stu.fScore,4);
	strncpy(stu.strName,name,10);
	strncpy(stu.strID,id,10);
	return is;
}
int main()
{
	CStudent stu1("MaWenTao","99001",88);
	CStudent stu2("LiMing","99002",92);
	CStudent stu3("WangFang","99003",89);
	CStudent stu4("YangYang","99004",90);
	CStudent stu5("DingNing","99005",80);
	fstream file1;
	file1.open("student.dat",ios::out|ios::in|ios::binary);
	file1<<stu1<<stu2<<stu3<<stu4<<stu5;
	CStudent *one=new CStudent("","");
	const int size=sizeof(CStudent);
	file1.seekp(size*4);
	file1>>*one;
	one->print();
	file1.seekp(size*1);
	file1>>*one;
	one->print();
	file1.seekp(size*2,ios::cur);
	file1>>*one;
	one->print();
	file1.close();
	delete one;
	return 0;
}
