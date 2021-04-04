//http://blog.csdn.net/yangtrees/article/details/8520870

//版本一
//单例类的C++实现 
/*#include <iostream>

using namespace std;

class Singleton
{
private:
	Singleton();    // 构造方法私有 
	static Singleton* instance;   //唯一实例 
	int var;   //成员变量（用于测试） 
public:
	static Singleton* getinstance();    //工厂方法（用来获得实例） 
	int getVar();   //获得var的值 
	void setVar(int);    //设置var的值 
	virtual ~Singleton(); 
}; 

Singleton::Singleton()  //构造方法实现 
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
	
	delete Singleton::getinstance();  //必须显式地删除
	return 0; 
} 
*/

//实现一个类，不能被继承，且只能被实例化3次（注意判断次数的位置，构造函数必须是私有的）
 
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
	A* p = NULL;   //不实例化 
	for(int i=0; i<5; i++)  //运行静态函数，判断n<3，然后调用构造函数n++,之后调用print所以输出1,2,3 
	{
		p = A::inital();
		if(p)
			p->print(); 
	} 
	return 0;
} 
