#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <ctime>

using namespace std;

char* filename = "C:\\Users\\asus\\Desktop\\t.txt";  // "D:\\Twilight.txt";

void topk(const int& K)
{
	double t=clock();
	ifstream infile;
	infile.open(filename);
	if(!infile)
		cout<<"Can not open file"<<endl;
		
	string s;
	map<string, int> wordcount;
	while(true)
	{
		infile>>s;
		if(infile.eof())
			break;
		wordcount[s]++;
	}
	
	cout<<"单词种类："<<wordcount.size()<<endl;
	
	//优先队列使用小顶堆，排在前面的数量少，使用">" 
	priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > > queueK;
	
	for(map<string, int>::iterator iter=wordcount.begin(); iter!=wordcount.end(); iter++)
	{
		queueK.push(make_pair(iter->second, iter->first));
		if(queueK.size() > K) 
			queueK.pop(); 
	} 
	
	pair<int, string> tmp;
	while(!queueK.empty())
	{
		tmp = queueK.top();
		queueK.pop();
		cout<<tmp.second<<"\t"<<tmp.first<<endl; 
	} 
	cout<<" < Elapsed Time: "<<(clock()-t)/CLOCKS_PER_SEC<<" >"<<endl; 
}

int main()
{
	int k;
	while(true)
	{ 
	   cout<<"put in k:"; 
	   cin>>k;
	   if(k == 0)
		  break;
	   topk(k);
	}
	return 0; 
} 
