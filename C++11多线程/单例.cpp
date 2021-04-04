#include <iostream>
#include <thread>

using namespace std;

mutex resource_mtx;

class MyCAS
{
private:
    MyCAS()
    {

    }

public:
    MyCAS* m_instance;
    static MyCAS* getInstance()
    {
        if(m_instance == NULL)  // 双重锁定
        {
            unique_lock<mutex> mymtx(resource_mtx);   // 自动加锁
            if(m_instance == NULL)
            {
                m_instance = new MyCAS();
                static CGarhuishou c1;
            }
        }
        
        return m_instance;
    }

    class CGarhuishou   // 类中套类，用来释放对象
    {
    public:
        ~CGarhuishou()
        {
            if(MyCAS::m_instance)
            {
                delete MyCAS::m_instance;
                MyCAS::m_instance = NULL;
            }
        }
    };
};

MyCAS* MyCAS::m_instance = NULL;

// 线程入口函数
void mythread()
{
    cout<<"我的线程开始了"<<endl;
    MyCAS* p_a = MyCAS::getInstance();
    cout<<"我的线程执行完毕了"<<endl;

}

int main()
{
    // MyCAS* p_a = MyCAS::getInstance();  // 单例类
    // MyCAS* p_b = MyCAS::getInstance();

    thread myobj1(mythread);
    thread myobj2(mythread);
    myobj1.join();
    myobj2.join();   // myobj2.detach();  //分离，将子线程与主线程分离开来，即子线程就不和主线程汇合，主线程不必等待子线程执行完毕

    return 0;
}

// https://www.notown.club/?p=458



// https://www.cnblogs.com/sunchaothu/p/10389842.html

#include <iostream>

class Singleton  // 懒汉
{
public:
    ~Singleton(){
        std::cout<<"destructor called!"<<std::endl;
    }
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
    static Singleton& get_instance(){
        static Singleton instance;
        return instance;

    }
private:
    Singleton(){
        std::cout<<"constructor called!"<<std::endl;
    }
};

int main(int argc, char *argv[])
{
    Singleton& instance_1 = Singleton::get_instance();
    Singleton& instance_2 = Singleton::get_instance();
    return 0;
}


#include <iostream>
// version1:
// with problems below:
// 1. thread is not safe
// 2. memory leak

class Singleton{
private:
    Singleton(){
        std::cout<<"constructor called!"<<std::endl;
    }
    Singleton(Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
    static Singleton* m_instance_ptr;
public:
    ~Singleton(){
        std::cout<<"destructor called!"<<std::endl;
    }
    static Singleton* get_instance(){
        if(m_instance_ptr==nullptr){
              m_instance_ptr = new Singleton;
        }
        return m_instance_ptr;
    }
    void use() const { std::cout << "in use" << std::endl; }
};

Singleton* Singleton::m_instance_ptr = nullptr;

int main(){
    Singleton* instance = Singleton::get_instance();
    Singleton* instance_2 = Singleton::get_instance();
    return 0;
}


#include <iostream>
#include <memory> // shared_ptr
#include <mutex>  // mutex

// version 2:
// with problems below fixed:
// 1. thread is safe now
// 2. memory doesn't leak

class Singleton{
public:
    typedef std::shared_ptr<Singleton> Ptr;
    ~Singleton(){
        std::cout<<"destructor called!"<<std::endl;
    }
    Singleton(Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
    static Ptr get_instance(){

        // "double checked lock"
        if(m_instance_ptr==nullptr){
            std::lock_guard<std::mutex> lk(m_mutex);
            if(m_instance_ptr == nullptr){
              m_instance_ptr = std::shared_ptr<Singleton>(new Singleton);
            }
        }
        return m_instance_ptr;
    }


private:
    Singleton(){
        std::cout<<"constructor called!"<<std::endl;
    }
    static Ptr m_instance_ptr;
    static std::mutex m_mutex;
};

// initialization static variables out of class
Singleton::Ptr Singleton::m_instance_ptr = nullptr;
std::mutex Singleton::m_mutex;

int main(){
    Singleton::Ptr instance = Singleton::get_instance();
    Singleton::Ptr instance2 = Singleton::get_instance();
    return 0;
}