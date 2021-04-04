#include <iostream>
#include <mutex>
#include <future>

using namespace std;

int mythread(int val)  // 线程入口函数
{
    cout<<"mythread() start "<<"threadid = "<<this_thread::get_id()<<endl;  /// 打印线程id
    chrono::milliseconds dura(5000);  // 5s
    this_thread::sleep_for(dura); 
    cout<<"mythread() end "<< "threadid = "<<this_thread::get_id()<<endl;
    return 5;
}

void mythread(std::promise<int>& tmp, int calc)
{
    // 做一系列复杂的操作
    calc++;
    calc *= 10
    // 做其他运算，比如整整花费了5s
    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);

    int result = calc;
    tmp.set_value(result);  // 保存结果
}

void mythread2(std::future<int>& tmpf)
{
    auto result = tmpf.get();
    cout<<"mythread2 result "<<result<<endl;
}

// int g_mycount = 0;  // 定义一个全局量
std::atomic<int> g_mycount = 0;  // 原子操作的int

// std::mutex g_my_mutex; // 互斥量

void mythread3()
{
    for(int i=0; i<10000000; i++)
    {
        // g_my_mutex.lock();
        g_mycount++;      // 对应的操作是原子操作（不会被打断)
        // g_my_mutex.unlock();
    }
}  

int main()
{
    cout<<"main "<<"threadid = "<<this_thread::get_id()<<endl;
    future<int> result = async(mythread, 1);   // 创建一个线程并开始执行
    cout<<"continue....!"<<endl;
    int def = 0;
    cout<<result.get()<<endl;   // get()等待mythread()线程执行完毕，拿到结果
    // result.wait();   // 等待线程返回，本身并不返回结果
      // async()传递额外的参数：该参数类型是launch类型(枚举类型)
        // 1) launch::deferred 表示线程入口函数调用被延迟到future的wait()或者get()调用时才执行，如果get()或者wait()
        // 没有被调用，线程不会被执行。launch::deferred延迟调用并没有创建新线程，是在主线程中调用线程入口函数
        // 2) launch::async 在调用async函数的时候开始创建线程
        // async()函数，默认用的就是launch::async | launch::deferred 标记 async(launch::async, mythread, 1)
    cout<<"I Love China!"<<endl;

    // std::packaged_task:打包任务，把任务包装起来
    // 是个类模板，它的模板参数是各种可调用对象，通过std::packaged_task来把各种可调用对象包装起来，方便将来作为线程入口
    cout<<"main "<<"threadid = "<<this_thread::get_id()<<endl;
    packaged_task<int(int)> mypt(mythread);  // 把函数mythread通过packaged_task包装起来
   
   /* packaged_task<int(int)> mypt([](int mypar){
        cout<<mypar<<endl;
        cout<<"mythread() start "<<"threadid = "<<this_thread::get_id()<<endl;
        std::chrono::milliseconds dura(5000);
        this_thread::sleep_for(dura);
        cout<<"mythread() end "<<"threadid = "<<this_thread::get_id()<<endl;
        return 5; 
    });*/

    thread t1(std::ref(mypt), 1);  // 线程直接开始执行
    t1.join();
    future<int> result = mypt.get_future();
    cout<<result.get()<<endl;

    // mypt(105);  // 直接调用，相当于函数调用
    // future<int> result = mypt.get_future();
    // cout<<result.get()<<endl;

    // std::promise 类模板，能够在某个线程中给他赋值，然后在其他线程中把这个值取出来用
    // 通过promise保存一个值，在将来某个时刻我们通过把一个future绑定到这个promise上来得到这个绑定的值
    std::promise<int> myprom;  
    thread t1(mythread, std::ref(myprom), 180);
    t1.join();

    // 获取结果值
    future<int> fu1 = myprom.get_future();
    // auto result = fu1.get();   // get只能调用一次
    // cout<<"result = "<<result<<endl;
    thread t2(mythread2, std::ref(fu1));
    t2.join();

    cout<<"I Love China!"<<endl;

    cout<<"main "<<"threadid = "<<this_thread::get_id()<<endl;
    future<int> result = std::async(mythread);
    cout<<"continue...."<<endl;

    std::future_status status = result.wait_for(std::chrono::seconds(1));  // 等待1s
    if(status == std::future_status::timeout)
    {
        // 超时：表示线程还没执行完
        cout<<"超时，线程还没有执行完毕"<<endl;
    }
    else if(status == std::future_status::ready)
    {
        // 表示线程成功返回
        cout<<"线程成功执行完毕，返回"<<endl;
        cout<<result.get()<<endl;
    }
    else if(status == std::future_status::deferred)  // 延迟
    {
        // 如果async的第一个参数被设置为std::launch::deferred，则本条件成立
        cout<<"线程被延迟执行"<<endl;
        cout<<result.get()<<endl;
    }
    
    /**
    std::future 的成员函数，get()函数转移数据(move)
    std::shared_future的get()函数复制数据
    */
    future<int> result = mypt.get_future();
    // shared_future<int> result_s(std::move(result));
    shared_future<int> result_s(result.share());
    // shared_future<int> result_s(mypt.get_future());



    /*
    原子操作：是在多线程中不会被打断的程序执行片段，原子操作，比互斥量效率更胜一筹
    互斥量的加锁一般是针对一个代码段(几行代码)，而原子操作针对的一般都是一个变量，而不是一个代码段
    atomic 原子操作针对: ++, --, +=, &=, |=, ^= 是支持的
    */
    thread myobj1(mythread3);
    thread myobj2(mythread3);
    myobj1.join();
    myobj2.join();
    cout<<"两个线程执行完毕，最终的g_mycount的结果是："<<g_mycount<<endl;

     /*
        std::mutex: 独占互斥量，自己lock时别人lock不了
        std::recursive_mutex: 递归的独占互斥量，允许同一个线程，同一个互斥量多次被lock()

        std::timed_mutex: 带超时功能的独占互斥量
               try_lock_for():  参数是一段时间，等待一段时间，如果拿到了锁或者等待超时没拿到锁就走下来
               try_lock_until(): 参数是一个未来的时间点，在这个未来的时间没到的时间内，如果拿到了锁那么久走下来；
                                                        如果时间到了也没拿到锁，也走下来
        std::recursive_timed_mutex: 带超时功能的递归独占互斥量
    */

    return 0;
}