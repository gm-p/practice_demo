#include <iostream>
#include <string>

using namespace std;

int main()
{
	string file = "D:/ERA5.1.1.2000.nc4";
	if(remove(file.c_str()) == -1)
		cout<<"fail"<<endl;
	cout<<"OK"<<endl;

	cout<<"sizeof(int) = "<<sizeof(int)<<endl;
	cout<<"sizeof(float) = "<<sizeof(float)<<endl;
	cout<<"sizeof(double) = "<<sizeof(double)<<endl;
	cout<<"sizeof(long) = "<<sizeof(long)<<endl;
	cout<<"sizeof(long long) = "<<sizeof(long long)<<endl;
	return 0;
}
