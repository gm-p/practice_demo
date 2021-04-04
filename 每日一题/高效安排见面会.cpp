#include <iostream>
#include <list>
#include <vector>

using namespace std;

// If 2 recuiting meetings are conflicting
bool IsConflict(const vector<bool>& v1, const vector<bool>& v2)
{
	for(int i=0; i<v1.size(); ++i)
		if(v1[i] && v2[i])
			return true;
	return false;
}

//merge 2 recruiting meetings: v2 will be held at the same time of v1
void Merge(vector<bool>& v1,const vector<bool>& v2)
{
	for(int i=0; i<v1.size(); ++i)
		v1[i] = v1[i] || v2[i];
}

void ArrangeRecruitings(vector<vector<bool> >& input, int check, int& curTime,
                      vector<list<int> >& curArrangement, int& bestTime, 
					  vector<list<int> >& bestArrangement)
{
	int m = input.size();
	if(check >= m)
	{
		if(curTime < bestTime)
		{
			bestTime = curTime;
			bestArrangement = curArrangement;
		}
		return ;
	}
	else
	{
		for(int i=0; i<=check; ++i)    //check: The meeting to check
		{
			if(curArrangement[i].empty())  //if already merged with other ones, just skip it
				continue;
			if(!IsConflict(input[i], input[check]))
			{
				vector<bool> bkI = input[i];
				Merge(input[i], input[check]);
				curArrangement[check].pop_back();
				curArrangement[i].push_back(check);
				
				ArrangeRecruitings(input, check+1, curTime, curArrangement, bestTime, bestArrangement);
				
				curArrangement[i].pop_back();
				curArrangement[check].push_back(check);
				
				input[i] = bkI;
			}
		}
		ArrangeRecruitings(input, check+1, ++curTime, curArrangement, bestTime, bestArrangement);
		
	}
}

int main()
{
	int m=3;   //meetings
	int n=4;   //students
	
	vector<vector<bool> > input(m, vector<bool>(n, false));
	input[0][0] = true;
	
	input[1][1] = true;
	input[1][2] = true;
	
	input[2][2] = true;
	input[2][3] = true;
	
	input[0][3] = true;
	
	int curTime = 1;
	int bestTime = m+1;
	vector<list<int> > curArrangement(m);
	vector<list<int> > bestArrangement(m);
	for(int i=0; i<m; ++i)
		curArrangement[i].push_back(i);
		
	ArrangeRecruitings(input, 1, curTime, curArrangement, bestTime, bestArrangement);
	
	cout<<"Total Time: "<<bestTime<<endl;
	for(int i=0; i<m; ++i)
	{
		cout<<i<<"):" ;
		if(bestArrangement[i].empty())
		{
			cout<<"none"<<endl;
			continue;
		}
		for(list<int>::const_iterator it=bestArrangement[i].begin(); it!=bestArrangement[i].end(); ++it)
			cout<<*it<<"-";
		
		cout<<endl;
		
	}
	return 0;
	
}

