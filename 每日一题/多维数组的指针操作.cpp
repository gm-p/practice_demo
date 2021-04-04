#include <iostream>
using namespace std;

template<typename T>
int f(T p)
{
	return (int)(p+1) - (int)p;
}

template<typename T>
int get(T p)    //相当于位操作：(100000-1) --> 01111; 
{
	return *((int*)(p+1) - 1);
}

int main()
{
	int a[2][2][2][2] = {{{{1, 2},{3, 4}}, {{5, 6},{7, 8}}},{{{9, 10},{11, 12}}, {{13, 14}, {15, 16}}}};
	int* p;
	int (*p1)[2];
	int (*p2)[2][2];
	int (*p3)[2][2][2];
	p = a[0][0][0];
	p1 = a[0][0];
	p2 = a[0];
	p3 = a;
	
	cout<<"p:\t"<<f(p)<<endl;    //4:  int* p
	cout<<"p1:\t"<<f(p1)<<endl;  //8=4*2  int (*p1)[2] 
	cout<<"p2:\t"<<f(p2)<<endl;  //16=8*2  int (*p2)[2][2] 
	cout<<"p3:\t"<<f(p3)<<endl;  //32
	
	cout<<"*p:\t"<<f(*p)<<endl;  //1
	cout<<"*p1:\t"<<f(*p1)<<endl;  //4  : 1指针4字节（相当于f(p)） 
	cout<<"*p2:\t"<<f(*p2)<<endl;  //8=4*2  (相当于f(p1)) 
	cout<<"*p3:\t"<<f(*p3)<<endl;  //16
	
	cout<<endl;
	cout<<"&a:\t"<<get(&a)<<endl;     //16 = a[1][1][1][1] 
	cout<<"&a[0]:\t"<<get(&a[0])<<endl;  //8=a[0][1][1][1] 
	cout<<"&a[0][0]:\t"<<get(&a[0][0])<<endl;  //4=a[0][0][1][1] 
	cout<<"*((int*)(&a[0][0][0]+1)-1):\t"<<get(&a[0][0][0])<<endl;  // 2= a[0][0][0][1] 
	cout<<*(*(*(&a[0][0]+1)-1)+1)<<endl; 
	 
	return 0; 
} 
