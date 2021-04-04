#include <iostream>

using namespace std;

void fun(int N)
{
	int factor=1;
	int count=0;
	int low, cur, high;
	while(N/factor)
	{
		low = N - (N/factor)*factor;
		cur = (N/factor)%10;
		high = N/(factor*10);
		switch(cur)
		{
			case 0:	count += high*factor;
					break;
			case 1:
					count += high*factor + low +1;
					break;
			default:
					count += (high+1)*factor;
					break; 
		} 
		factor *= 10;
	} 
	cout<<count<<endl;
} 

int main()
{
	int n;
	while(cin>>n)
	{
		if(n == -1)
			break;
		fun(n); 
	} 
	return 0;
} 
