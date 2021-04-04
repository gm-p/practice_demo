//http://blog.csdn.net/yangtrees/article/details/8520870

//�汾һ
//�������C++ʵ�� 
/*#include <iostream>

using namespace std;

class Singleton
{
private:
	Singleton();    // ���췽��˽�� 
	static Singleton* instance;   //Ψһʵ�� 
	int var;   //��Ա���������ڲ��ԣ� 
public:
	static Singleton* getinstance();    //�����������������ʵ���� 
	int getVar();   //���var��ֵ 
	void setVar(int);    //����var��ֵ 
	virtual ~Singleton(); 
}; 

Singleton::Singleton()  //���췽��ʵ�� 
{
	this->var = 20;
	cout<<"Singleton Constructor"<<endl; 
}
 
Singleton* Singleton::instance = new Singleton;

Singleton* Singleton::getinstance()
{
	return instance; 
} 

int Singleton::getVar()
{
	return this->var;
}

void Singleton::setVar(int var)
{
	this->var = var;
} 


Singleton::~Singleton()
{
	cout<<"Singleton Destructor"<<endl; 
} 

int main()
{
	Singleton* ton1 = Singleton::getinstance();
	Singleton* ton2 = Singleton::getinstance();
	
	if(ton1 == ton2)
		cout<<"ton1 = ton2"<<endl;
	
	cout<<"ton1 var = "<<ton1->getVar()<<endl;
	cout<<"ton2 var = "<<ton2->getVar()<<endl;
	
	ton1->setVar(150);
	cout<<"ton1 var = "<<ton1->getVar()<<endl;
	cout<<"ton2 var = "<<ton2->getVar()<<endl;
	
	delete Singleton::getinstance();  //������ʽ��ɾ��
	return 0; 
} 
*/

//ʵ��һ���࣬���ܱ��̳У���ֻ�ܱ�ʵ����3�Σ�ע���жϴ�����λ�ã����캯��������˽�еģ�
 
#include <iostream>

using namespace std;

class A 
{
private:
	A()
	{
		n++;
	} 
	static int n;
public:
	static A* inital()
	{
		if(n < 3)
			return new A;
		else
			return 0; 
	} 
	void print()
	{
		cout<<n<<endl;
	} 
};
int A::n = 0;

int main()
{
	A* p = NULL;   //��ʵ���� 
	for(int i=0; i<5; i++)  //���о�̬�������ж�n<3��Ȼ����ù��캯��n++,֮�����print�������1,2,3 
	{
		p = A::inital();
		if(p)
			p->print(); 
	} 
	return 0;
} 
