#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>
#include <array>
#include <vector>
#include <algorithm>

void f1(int n)
{
	for(int i=0; i<5; i++)
	{
		std::cout<<"Thread "<<n<<" executing..."<<std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(10)); //睡眠
	}
}

void f2(int& n)
{
	for(int i=0; i<5; i++)
	{
		std::cout<<"Thread 2 executing..."<<std::endl;
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));  // 睡眠
	}
}

// int main()
// {
// 	int n = 0;
// 	//空线程变量创建
// 	std::thread t1;
	
// 	// 模板方法线程变量创建
// 	std::thread t2(f1, n+1);  // 按值传递
// 	std::thread t3(f2, std::ref(n));  // std::ref表示按引用传递
// 	// 移动语义定义方法线程变量创建
// 	// std::move(t3)表示强制t3为右值
// 	// t4现在运行f2()函数，t3不在是一个线程变量，t3将权限交给t4
// 	std::thread t4(std::move(t3));

// 	t2.join(); // 阻塞主线程，直到t2线程结束
// 	t4.join(); // 阻塞主线程，直到t4线程结束

// 	std::cout<<"Final value of n is "<<n<<std::endl;
// 	return 0;	
// } 

/* std::thread 赋值操作 */
void thread_task(int n)
{
	std::this_thread::sleep_for(std::chrono::seconds(n));
	std::cout<<"hello thread "<<std::this_thread::get_id()<<" paused "<<n<<" seconds"<<std::endl;
}

template<typename T, int div>
void Divide()
{
	static_assert(div!=0, "Bad arguments...");
}

int main()
{
	std::thread threads[5]; // 空线程变量
	std::cout<<"Spawning 5 threads ...\n";
	for(int i=0; i<5; i++)
	{
		// 移动语义赋值，std::thread(thread_task, i+1)为右值
		threads[i] = std::thread(thread_task, i+1);
	}
	std::cout<<"Done spawning threads! Now wait for them to join"<<std::endl;
	for(auto& t: threads)
	{
		t.join(); // 阻塞主线程
	}
	std::cout<<"All threads joined."<<std::endl;
	// std::vector<int> v{2, 1, 3, 6, 5, 4, 9, 8, 7, 0};
	// sort(v.begin(), v.end());
	// auto it = lower_bound(v.begin(), v.end(), 2);  // 不小于2的最左位置的迭代器
	// std::cout<<*it << '\t' <<it - v.begin()<<std::endl;
	// it = upper_bound(v.begin(), v.end(), 2);    // 大于2的位置的迭代器
	// std::cout<<*it<< '\t' <<it - v.begin()<<std::endl;
	std::cout<<__cplusplus<<std::endl;
	return 0;
}
