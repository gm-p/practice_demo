#include <iostream>
using namespace std;
inline float fmax(float x,float y)
{
	return x>y?x:y;
}
int main()
{
	float a;
	a=fmax(5,10);
	cout<<"������Ϊ��"<<a<<"\n";
	return 0;
}