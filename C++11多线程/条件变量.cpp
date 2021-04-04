#include <iostream>
#include <list>
#include <mutex>

using namespace std;

class A
{
private:
    list<int> msgRecvQueue;  // 容器(消息队列)
    mutex my_mutex1;  // 创建一个互斥量
    condition_variable my_cond;  // 生成一个条件变量对象
public:
    void inMsgRecvQueue()  // 把收到的消息放入到一个队列的线程
    {   
        for(int i=0; i<100000; ++i)
        {
            cout<<"inMsgRecvQueue()执行，插入一个元素"<<i<<endl;
            unique_lock<mutex> sbguard1(my_mutex1);
            msgRecvQueue.push_back(i);
            my_cond.notify_one();  // 我们尝试把wait()的线程唤醒，执行完这行，那么outMsgRecvQueue()里边的wait就会被唤醒

        }
    }

    void outMsgRecvQueue()   // 把数据从消息队列中取出的线程
    {
        int command = 0;
        while(true)
        {
            unique_lock<mutex> sbguard1(my_mutex1);
            // wait()用来等一个东西，第二个参数lambda表达式返回true，那么wait()直接返回；返回值是false，那么wait将解锁互斥量并堵塞到本行,
            //  堵到其他某个线程调用notify_one()成员函数为止
            // 如果wait()没有第二个参数，那么就跟第二个参数lambda表达式返回false效果一样
            // 当其他线程用notify_one()将本wait(原来是睡眠/堵塞)的状态唤醒后，wait就开始恢复干活了
            //     wait()不断得到尝试重新获取互斥量锁,如果获取不到，那么流程就卡在wait这里等着获取，
            //     如果获取到了锁，那么wait就继续
            my_cond.wait(sbguard1, [this] {
                if(!msgRecvQueue.empty())
                    return true;
                return false;
            });

            command = msgRecvQueue.front();
            msgRecvQueue.pop_front();
            sbguard1.unlock();   // unique_lock的灵活性，可以随时unlock解锁，以免锁住太长时间
            cout<<"outMsgRecvQueue()执行，取出一个元素"<<command<<endl;
        }
    }
};