#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
	shared_ptr<int> ptr_num;
	ptr_num = make_shared<int>(3);
	cout<<"ptr_num��ַ��"<<ptr_num<<endl;
	cout<<"ptr_numֵ��"<<*ptr_num<<endl;
	cout<<"use_count:"<<ptr_num.use_count()<<endl;
	
	shared_ptr<string> ptrStr = make_shared<string>("hello");
	cout<<"�޸�ǰ��"<<ptrStr<<"->"<<*ptrStr<<endl;
	if(ptrStr && !ptrStr->empty())
	{
		*ptrStr = "LiuSir";	
	} 
	cout<<"�޸ĺ�"<<ptrStr<<"->"<<*ptrStr<<endl;
	
	unique_ptr<string> u1(new string("hello ls"));
	cout<<"u1:"<</*u1<<*/"->"<<*u1<<endl;
	unique_ptr<string> u2(u1.release());   //������Ȩ��u1ת�Ƹ�u2    release��u1�ÿ�
	cout<<"u2:"<</*u2<<*/"->"<<*u2<<endl;
	unique_ptr<string> u3(new string("u3"));
	u2.reset(u3.release());  //������Ȩ��u3ת�Ƶ�u2��reset�ͷ���u2ԭ��ָ����ڴ�
	cout<<"u2:"<</*u2<<*/"->"<<*u2<<endl;
	
	auto u = u2.release();  // ɾ��u2 
	delete(u); 
	return 0;
}
