#include <iostream>
#include <queue>
#include <utility>

using namespace std;

queue<pair<int, int> > mov;
int a[100][100];


//�ƶ������������������������
void IntialQueue()
{
	mov.push(make_pair(0,1));  //right
	mov.push(make_pair(1,0));  //down
	mov.push(make_pair(0,-1)); //left
	mov.push(make_pair(-1,0)); //up 
} 

void PrintMat(int s)
{
	int sum = s*s;
	int x = (s-1)/2, y = (s-1)/2;  //ע����ʼλ�ã���Ȼ�����ż���߳����Ϊ��
	a[x][y] = 1;
	int current = 2;
	if(current > sum)
	   return ;
	int radius=1, addradius=1;  // radius:ÿ����ת�ı߳�   addradius���߳�����ֵ
	
	pair<int, int> tmp;
	while(1)
	{
		for(int i=0; i<radius && current<=sum; i++)   // current<=sum ע����"<="
		{
			x += mov.front().first;
			y += mov.front().second;
			a[x][y] = current;
			current++; 
		} 
		if(current > sum)
		    return ;
		//ÿ��������һ��radius����
		addradius = (addradius+1)%2;
		radius += addradius;
		
		tmp = mov.front();
		mov.pop();
		mov.push(tmp); 
	} 
} 
int main()
{
	int n;
	cin>>n;
	IntialQueue();
	PrintMat(n);
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(a[i][j] < 10)
				cout<<" ";   //����
			cout<<a[i][j]<<" "; 
		} 
		cout<<endl;
	} 
} 
