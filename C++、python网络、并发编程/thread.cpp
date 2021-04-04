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
 thread创建线程 
1.创建一个函数，把改函数作为线程的入口地址
void readTheval(int num)
{
	cout<<"我是读线程"<<this_thread::get_id();
	cout<<" 我读到的数据是："<<num<<endl;
}
int main()
{
	thread t(readTheval, 5);
	t.join();
	return 0;	
} 

2.创建一个类，并编写圆括号重载函数，初始化一个该类的对象，把该类的对象作为线程入口地址
class CircleReload
{
public:
	void operator()()
	{
		cout<<"创建一个线程 "<<this_thread::get_id()<<endl;
		cout<<"线程执行结束!"<<endl;
	}	
};
int main()
{
	CircleReload acase;
	thread t(acase);
	t.join();
	return 0;
}

3.lambda表达式创建线程
int main()
{
	auto OneThread = [](){
		cout<<"lambda表达式创建线程"<<endl;
		cout<<this_thread::get_id()<<endl;
	};
	thread t(OneThread);
	t.join();
	return 0;
} 

4.把某个类中的某个函数作为线程的入口地址
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
多个线程的创建、管理
#include <vector>
void TestThread()
{
	cout<<"我是线程 "<<this_thread::get_id()<<endl;	
	cout<<"线程"<<this_thread::get_id()<<"执行结束"<<endl;
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
async创建线程(创建异步任务)
要是launch::async省略的话，系统会把它当成launch::async | launch::deferred
#include <future>
int TestThread(int num)
{
	cout<<"我是线程"<<this_thread::get_id()<<endl;
	cout<<"线程"<<this_thread::get_id()<<"结束"<<endl;
	return num*10;
}
int main()
{
	cout<<"主线程"<<this_thread::get_id()<<endl; 
	future<int> result = async(launch::async, TestThread, 6);
	cout<<result.get()<<endl;
	cout<<"主线程执行结束"<<endl;
	return 0;
}
*/

/* 
future_status判断系统最终有无创建线程
#include <future>
int getValue(int num)
{
	cout<<"我的ID是："<<this_thread::get_id()<<endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	return num*2;
} 
int main()
{
	shared_future<int> result = async(getValue, 5);
	future_status status = result.wait_for(chrono::seconds(4));
	if(status == future_status::timeout)
	{
		cout<<"任务超时，还没执行完"<<endl;
	}
	else if(status == future_status::ready)
	{
		cout<<"给我的时间够用，我已经准备好了"<<endl;
		cout<<result.get()<<endl;
	}
	else if(status == future_status::deferred)
	{
		cout<<"线程被延迟执行"<<endl;
		cout<<result.get()<<endl;
	}
	return 0;
}
*/

/*
packaged_task 打包任务，把任务包装起来，是一个类模板，是一个用来包装可调用对象的可调用对象
#include <future>
int TestThread(int num)
{
	cout<<"我是线程"<<this_thread::get_id()<<endl;
	cout<<"线程"<<this_thread::get_id()<<"结束"<<endl;
	return num*10;
}
int main()
{
	packaged_task<int(int)> obj(TestThread);  // 包装
	thread t(ref(obj), 6);
	t.join();
	future<int> result = obj.get_future();
	cout<<result.get()<<endl; 
	return 0;
}
*/

/*
promise一个类模板，能够在某个线程中给它赋值，然后可以在其它线程中，把这个值取出来用
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
	future<int> result = prom.get_future(); //future和promise绑定，用于获取线程返回值
	cout<<result.get()<<endl;
	return 0;
}
*/



