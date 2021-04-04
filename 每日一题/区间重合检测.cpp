//http://blog.csdn.net/yangtrees/article/details/8256631

//解法一
/*#include <iostream>
#include <algorithm>

using namespace std;

struct region
{
	int start;
	int over;
	bool operator<(const region r) const
	{
		return start < r.start;
	} 
}; 

int check(region m[], int length, int testId)
{
	int low=0, high=length+1;
	int mid;
	while(low <= high)
	{ 
		mid = low + ((high - low) >> 1);
		if(testId >= m[mid].start)
	  		low = mid + 1;
		else
			high = mid - 1;
    }
	return high;   //返回的是high值，此时high小于等于mid，小于low 
}

int main()
{
	region r[30], merged[30], test;
	int n;   //count of array
	int m;   //count of merged array
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>r[i].start>>r[i].over;
	cin>>test.start>>test.over;
	
	sort(r, r+n);   //sort by start time
	cout<<endl;
	cout<<"Sorted Region:"<<endl;
	for(int i=0; i<n; i++)
		cout<<r[i].start<<" "<<r[i].over<<endl;
	cout<<endl;
	
	//mergeRegions;
	m=0;
	int lasthigh = r[0].over;
	merged[0].start = r[0].start;
	merged[0].over = r[0].over;
	for(int i=1; i<n; i++)
	{
		if(lasthigh >= r[i].start)
		{
			lasthigh = lasthigh > r[i].over ? lasthigh : r[i].over;
			merged[m].over = lasthigh; 
		} 
		else  //扩展一个新的区间 
		{
			m++;
			merged[m].start = r[i].start;
			merged[m].over = r[i].over;
			lasthigh = r[i].over; 
		} 
	} 
	 
	 cout<<"Merge Region:"<<endl;
	 for(int i=0; i<=m; i++)
	 	cout<<merged[i].start<<" "<<merged[i].over<<endl;
	 cout<<endl;
	 
	 int startId = check(merged, m, test.start);
	 int overId = check(merged, m, test.over);
	 if(startId == overId && test.over <= merged[overId].over)
	 	cout<<"OK! The test line is in the set."<<endl;
	 else
	 	cout<<"False! The test line is not in the  set."<<endl; 
	  
	return 0;
} */



//解法二
#include <iostream>
#include <cstring>

using namespace std;

#define SIZE 100

int father[SIZE];
int count[SIZE];

void initail(int num)
{
	for(int i=0; i<num; i++)
	{
		father[i] = i;  //每个集合的代表是自己 
		count[i] = 1;  //代表一个元素 
	} 
} 

void merge(int x, int y)
{
	if(father[x] == father[y])
		return ;
	else
	{
		if(count[x] >= count[y])
			father[y] = father[x];
		else
			father[x] = father[y];
		count[father[x]]++; 
	} 
} 

int main()
{
	memset(father, -1, sizeof(father));
	memset(count, 1, sizeof(count)); 
	int n, t0, t1;
	cin>>n;
	while(n--) 
	{
		cin>>t0>>t1;
		if(t0>t1)
			swap(t0, t1);
		for(int i=t0+1; i<=t1; i++)
			merge(t0, i); 
	} 
	int test0, test1;
	cin>>test0>>test1;
	if(father[test0] == father[test1])
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0; 
} 
