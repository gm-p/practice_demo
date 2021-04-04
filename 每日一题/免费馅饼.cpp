#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int dp[1001][12];

int main()
{
	int i,j;
	int maxtime = 0;
	int n;
	int t, x;
	while(scanf("%d",&n), n!=0)
	{
		memset(dp, 0, sizeof(dp));
		for(i=0; i<n; i++)
		{
			scanf("%d %d",&x,&t);
			dp[t][x]++;
			if(maxtime < t)
				maxtime = t;
		}
		for(i=maxtime-1; i>=0; i--)
		{
			dp[i][0] += max(dp[i+1][0], dp[i+1][1]);
			for(j=1; j<11; j++)
				dp[i][j] += max(max(dp[i+1][j-1], dp[i+1][j]), dp[i+1][j+1]); 
		}
		printf("%d\n", dp[0][5]);
	}
	return 0;
}

