#include <iostream>


using namespace std;


int main()
{
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