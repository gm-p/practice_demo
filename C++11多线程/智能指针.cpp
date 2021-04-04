#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
	shared_ptr<int> ptr_num;
	ptr_num = make_shared<int>(3);
	cout<<"ptr_num地址："<<ptr_num<<endl;
	cout<<"ptr_num值："<<*ptr_num<<endl;
	cout<<"use_count:"<<ptr_num.use_count()<<endl;
	
	shared_ptr<string> ptrStr = make_shared<string>("hello");
	cout<<"修改前："<<ptrStr<<"->"<<*ptrStr<<endl;
	if(ptrStr && !ptrStr->empty())
	{
		*ptrStr = "LiuSir";	
	} 
	cout<<"修改后："<<ptrStr<<"->"<<*ptrStr<<endl;
	
	unique_ptr<string> u1(new string("hello ls"));
	cout<<"u1:"<</*u1<<*/"->"<<*u1<<endl;
	unique_ptr<string> u2(u1.release());   //将所有权从u1转移给u2    release将u1置空
	cout<<"u2:"<</*u2<<*/"->"<<*u2<<endl;
	unique_ptr<string> u3(new string("u3"));
	u2.reset(u3.release());  //将所有权从u3转移到u2，reset释放了u2原来指向的内存
	cout<<"u2:"<</*u2<<*/"->"<<*u2<<endl;
	
	auto u = u2.release();  // 删除u2 
	delete(u); 
	return 0;
}
