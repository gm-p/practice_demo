#include <iostream>
#include <queue>

using namespace std;

struct QNode
{
	int v, r;  //v is value, r is remainder
	QNode(int vv, int rr):v(vv), r(rr) {}
	QNode():v(0), r(0) {}
};

int main()
{
	int N;
	while(cin>>N)
	{
		queue<QNode> q;
		q.push(QNode(1,1));
		while(!q.empty())
		{
			vector<bool> bN(N, false);
			int s=q.size();
			while(s--)
			{
				QNode t = q.front();
				if(t.r == 0)
				{
					cout<<"N:"<<N<<" M:"<<t.v/N<<" n*m:"<<t.v<<endl;
					goto ok;
				}
				q.pop();
				if(!bN[t.r * 10 % N])
				{
					bN[(t.r * 10 + 1)%N] = true;
					q.push(QNode((t.v * 10 + 1), (t.r * 10 + 1)%N));
				}
			}
		}
		ok: ;
	}
	return 0;
}
