#include <iostream>
#include <thread>

using namespace std;

//class Data
//{
//public:
//	void getMsg(int i, int j)
//	{
//		cout<<"child thread"<<i<<"......"<<j<<endl;	
//	}	
//};
//
//int main()
//{
//	Data d;
//	cout<<"parent thread......"<<endl;
//	int i = 1;
////	thread t(&Data::getMsg, &d, i);
////	t.join();
//	thread threads[5];
//	int j = 100;
//	for(int i=0; i<5; i++)
//	{
//		threads[i] = thread(&Data::getMsg, &d, i, j);
//		threads[i].join();
//		j++;
//	}
//	cout<<"main end....."<<endl;
//	return 0;
//}

/*
 thread�����߳� 
1.����һ���������Ѹĺ�����Ϊ�̵߳���ڵ�ַ
void readTheval(int num)
{
	cout<<"���Ƕ��߳�"<<this_thread::get_id();
	cout<<" �Ҷ����������ǣ�"<<num<<endl;
}
int main()
{
	thread t(readTheval, 5);
	t.join();
	return 0;	
} 

2.����һ���࣬����дԲ�������غ�������ʼ��һ������Ķ��󣬰Ѹ���Ķ�����Ϊ�߳���ڵ�ַ
class CircleReload
{
public:
	void operator()()
	{
		cout<<"����һ���߳� "<<this_thread::get_id()<<endl;
		cout<<"�߳�ִ�н���!"<<endl;
	}	
};
int main()
{
	CircleReload acase;
	thread t(acase);
	t.join();
	return 0;
}

3.lambda���ʽ�����߳�
int main()
{
	auto OneThread = [](){
		cout<<"lambda���ʽ�����߳�"<<endl;
		cout<<this_thread::get_id()<<endl;
	};
	thread t(OneThread);
	t.join();
	return 0;
} 

4.��ĳ�����е�ĳ��������Ϊ�̵߳���ڵ�ַ
class Data
{
public:
	void GetMsg(int i, int j)
	{
		cout<<"GetMsg run....."<<endl;
		cout<<"i = "<<i<<" , j = "<<j<<endl;
	}
	
	void SaveMsg()
	{
		cout<<"SaveMsg run...."<<endl;
	}
}; 
int main()
{
	Data d;
	int i = 2, j = 3;
	thread t1(&Data::GetMsg, &d, i, j);
	thread t2(&Data::SaveMsg, &d);
	t1.join();
	t2.join(); 
	return 0;
} 
*/
/*
����̵߳Ĵ���������
#include <vector>
void TestThread()
{
	cout<<"�����߳� "<<this_thread::get_id()<<endl;	
	cout<<"�߳�"<<this_thread::get_id()<<"ִ�н���"<<endl;
} 
int main()
{
	vector<thread> vecThread;
	for(int i=0; i<5; i++)
		vecThread.push_back(thread(TestThread));
	for(int i=0; i<5; i++)
		vecThread[i].join();
	return 0;
}
*/

/*
async�����߳�(�����첽����)
Ҫ��launch::asyncʡ�ԵĻ���ϵͳ���������launch::async | launch::deferred
#include <future>
int TestThread(int num)
{
	cout<<"�����߳�"<<this_thread::get_id()<<endl;
	cout<<"�߳�"<<this_thread::get_id()<<"����"<<endl;
	return num*10;
}
int main()
{
	cout<<"���߳�"<<this_thread::get_id()<<endl; 
	future<int> result = async(launch::async, TestThread, 6);
	cout<<result.get()<<endl;
	cout<<"���߳�ִ�н���"<<endl;
	return 0;
}
*/

/* 
future_status�ж�ϵͳ�������޴����߳�
#include <future>
int getValue(int num)
{
	cout<<"�ҵ�ID�ǣ�"<<this_thread::get_id()<<endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	return num*2;
} 
int main()
{
	shared_future<int> result = async(getValue, 5);
	future_status status = result.wait_for(chrono::seconds(4));
	if(status == future_status::timeout)
	{
		cout<<"����ʱ����ûִ����"<<endl;
	}
	else if(status == future_status::ready)
	{
		cout<<"���ҵ�ʱ�乻�ã����Ѿ�׼������"<<endl;
		cout<<result.get()<<endl;
	}
	else if(status == future_status::deferred)
	{
		cout<<"�̱߳��ӳ�ִ��"<<endl;
		cout<<result.get()<<endl;
	}
	return 0;
}
*/

/*
packaged_task ������񣬰������װ��������һ����ģ�壬��һ��������װ�ɵ��ö���Ŀɵ��ö���
#include <future>
int TestThread(int num)
{
	cout<<"�����߳�"<<this_thread::get_id()<<endl;
	cout<<"�߳�"<<this_thread::get_id()<<"����"<<endl;
	return num*10;
}
int main()
{
	packaged_task<int(int)> obj(TestThread);  // ��װ
	thread t(ref(obj), 6);
	t.join();
	future<int> result = obj.get_future();
	cout<<result.get()<<endl; 
	return 0;
}
*/

/*
promiseһ����ģ�壬�ܹ���ĳ���߳��и�����ֵ��Ȼ������������߳��У������ֵȡ������
#include <future>
void myThread(promise<int>& pro, int num)
{
	num *= 2;
	pro.set_value(num);
}
int main()
{
	promise<int> prom;
	thread t(myThread, ref(prom), 66);
	t.join();
	future<int> result = prom.get_future(); //future��promise�󶨣����ڻ�ȡ�̷߳���ֵ
	cout<<result.get()<<endl;
	return 0;
}
*/



