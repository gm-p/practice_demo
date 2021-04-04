// #include <iostream>

// using namespace std;

// template<typename T>
// class SmartPoint
// {
// public:
//     SmartPoint(T* p=NULL)
//     {
//         _ptr = p;
//         if(p)
//         {
//             _count = 1;
//         }
//         else
//         {
//             _count = 0;
//         }
//     }

//     ~SmartPoint()
//     {
//         if(--_count == 0)
//             delete _ptr;
//     }

//     SmartPoint(const SmartPoint& sp)
//     {
//         if(this != &sp)
//         {
//             _ptr = sp._ptr;
//             _count = sp._count;
// 			_count++;
//         }
//     }

//     SmartPoint& operator=(const SmartPoint& sp)
//     {
//         if(_ptr == sp._ptr)
//             return *this;
//         if(_ptr)
//         {
//             _count--;
//             if(_count == 0)
//                 delete _ptr;
           
//         } 
//         _ptr = sp._ptr;
//         _count = sp._count;
// 		_count++;
//         return *this;
//     }

//     T* operator->()
//     {
//         if(_ptr)
//             return _ptr;
//     }

//     T& operator*()
//     {
//         if(_ptr)
//             return *_ptr;
//     }

//     size_t use_count()
//     {
//         return _count;
//     }

// private:
//     T* _ptr;
//     int _count;
// };

// void Use(SmartPoint<char> p)
// {
//     int n = p.use_count();
//     cout<<"Use() "<<n<<endl;
// }

// int main()
// {
//     SmartPoint<char> sp1(new char);
//     Use(sp1);
//     SmartPoint<char> sp2(sp1);
//     SmartPoint<char> sp3;
//     sp3 = sp1;
//     int n = sp1.use_count();
//     cout<<n<<endl;
//     cout<<sp3.use_count()<<endl;
//     return 0;
// }

// shared_ptr与weak_ptr配合使用
// #include <iostream>
// #include <memory>

// using namespace std;

// class B;

// class A
// {
// public:
//     //shared_ptr<B> _pb;  // 循环引用的bug
//     weak_ptr<B> _pb;
// };

// class B
// {
// public:
//     // shared_ptr<A> _pa;    // 循环引用内存无法释放
//     weak_ptr<A> _pa;      // weak_ptr不会增加引用计数
// };

// int main()
// {
//     shared_ptr<A> pa = make_shared<A>();
//     shared_ptr<B> pb = make_shared<B>();
//     cout<<"pa count:"<<pa.use_count()<<endl;
//     cout<<"pb count:"<<pb.use_count()<<endl;
//     pa->_pb = pb;
//     pb->_pa = pa;
//     cout<<"pa count:"<<pa.use_count()<<endl;
//     cout<<"pb count:"<<pb.use_count()<<endl;
//     return 0;
// }


// #include <iostream>
// #include <future>
// #include <thread>
// #include <exception>
// #include <cstring>

// using namespace std;

// struct PF
// {
//     string name;
//     int age;
// };

// void get_int(promise<PF>& prom)
// {
//     try
//     {
//         struct PF pf;
//        // memset(&pf, 0, sizeof(pf));
//         pf.name = "test";
//         pf.age = 10;
//         // 设置共享状态
//         //cout<<pf.name<<"\t"<<pf.age<<endl;
//         prom.set_value(pf);
//     }
//     catch(exception)
//     {
//     	cout<<"hahah"<<endl;
//         prom.set_exception(current_exception());
//     }
// }

// void print_int(future<PF>& fut)
// {
//     try
//     {
//         PF pf;
//         //memset(&pf, 0, sizeof(pf));
//         // 获取共享状态
//         pf = fut.get();
//         cout<<"age:"<<pf.age<<endl;
//         cout<<"name:"<<pf.name<<endl;
//     }
//     catch(exception& e)
//     {
//         cout<<"exception: "<<e.what()<<endl;
//     }
// }

// int main()
// {
//     PF pf;
//     //memset(&pf, 0, sizeof(pf));
//     //生成对象
//     promise<PF> prom;
//     //thread t1(get_int, ref(prom));
//     //t1.join();
//     thread* t1 = new thread(get_int, ref(prom));
//     t1->join();
//     // 与future关联
//     future<PF> fut = prom.get_future();
//     thread* t2 = new thread(print_int, ref(fut));
//     t2->join();
//     delete t1;
//     delete t2;

//     return 0;
// } // https://mp.weixin.qq.com/s/dshjaVMMIM_Ek8uLrF4TiQ


// #include <iostream>
// #include <future>
// #include <string>
// // #include <windows.h>

// using namespace std;

// void fun1()
// {
//     // Sleep(500);
//     chrono::milliseconds dura(500);
//     this_thread::sleep_for(dura);
//     cout<<"fun1..."<<endl;
// }

// void fun2(int n)
// {
//     // Sleep(100);
//     chrono::milliseconds dura(100);
//     this_thread::sleep_for(dura);
//     cout<<"fun2 n:"<<n<<endl;
// }

// string fun3(const string& str)
// {
//     chrono::milliseconds dura(100);
//     this_thread::sleep_for(chrono::seconds(1));
//     cout<<str<<endl;
//     return str;
// }

// void fun5(const string& str)
// {
//     cout<<"hello :"<<str<<endl;
// }

// int main()
// {
//     auto pfun1 = async(fun1);
//     auto pfun2 = async(fun2, 2);
//     auto pfun3 = async(fun3, "hello async");

//     auto pfun4 = async([]{
//         cout<<"pfun4"<<endl;
//     });
//     // 绑定函数
//     auto pfun5 = async(bind(fun5, "bind"));
//     // 获取返回值

//     cout<<"pfun3: "<<pfun3.get()<<endl;
//     return 0;
// }

// lambda表达式： 
// [capture] (parameters) mutable ->return-type {statement}
// std::function对象是对C++中现有的可调用实体的一种类型安全的包裹（我们知道像函数指针这类可调用实体，是类型不安全的）
// #include <iostream>
// #include <functional>

// using namespace std;

// int main()
// {
//     function<void(int)> pfun;
//     pfun = [](int x){
//         cout<<"x: "<<x<<endl;
//     };
//     pfun(3);
//     return 0;
// }


// 异常
// #include <iostream>

// using namespace std;

// int Div(int a, int b)
// {
//     if(b == 0)
//         throw "b is zero, please checked!!!";
//     return a / b;
// }

// int main()
// {
//     try
//     {
//         int a = 1, b = 0;
//         cout<<Div(a, b)<<endl;
//     }
//     catch(const char* e)
//     {
//         cout<<e<<endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <stdexcept>
// #include <exception>

// using namespace std;

// void run_error()
// {
//     throw runtime_error("run_error test");
// }

// void test_char()
// {
//     throw "char is test";
// }

// int main()
// {
//     try
//     {
//         run_error();
//     }
//     catch(exception& e)
//     {
//         cout<<e.what()<<endl;
//     }

//     try
//     {
//         test_char();
//     }
//     catch(string& str)
//     {
//         cout<<str<<endl;
//     }
//     catch(exception& e)
//     {
//         cout<<e.what()<<endl;
//     }
//     catch(const char* e)
//     {
//         cout<<e<<endl;
//     }

//     return 0;
// }

// 空class是一个1字节
#include <iostream>

using namespace std;

class Demo
{

};

class Device: public Demo
{
public:
    int a;
};

int main()
{
    Demo d;
    cout<<"sizeof(Demo): "<<sizeof(Demo)<<endl;
    cout<<"sizeof(Device): "<<sizeof(Device)<<endl; //4B 空基类被继承后由于没有任何数据成员，所以子类优化掉基类所占的1 byte
    string s;
    cout<<"sizeof(str):"<<sizeof(s)<<endl; // 4
    return 0;
}
