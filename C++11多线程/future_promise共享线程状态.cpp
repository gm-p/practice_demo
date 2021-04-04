#include <iostream>
#include <thread>
#include <future>
#include <exception>
#include <cstring>

using namespace std;

struct PF
{
	char name[128];
	int age;
};

void get_int(promise<PF>& prom)
{
	try
	{
		PF pf;
		memset(&pf, 0, sizeof(pf));
		memcpy(pf.name, "test", 5);
		pf.age = 10;
		//…Ë÷√π≤œÌ◊¥Ã¨
		prom.set_value(pf); 
	}
	catch(exception)
	{
		prom.set_exception(current_exception());
	}
}

void print_int(future<PF>& fut)
{
	try
	{
		PF pf;
		memset(&pf, 0, sizeof(pf));
		pf = fut.get();
		cout<<"age: "<<pf.age<<endl;
		cout<<"name: "<<pf.name<<endl;
	}
	catch(exception& e)
	{
		cout<<"exception: "<<e.what()<<endl;
	}
}

int main()
{
	PF pf;
	memset(&pf, 0, sizeof(pf));
	promise<PF> prom;
	future<PF> fut = prom.get_future();
	thread t1(get_int, ref(prom));
	thread* t2 = new thread(print_int, ref(fut));
	t1.join();
	t2->join();
	delete t2;
	return 0;
}
