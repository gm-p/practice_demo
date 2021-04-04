/*
��һ�������������
Input:
�����һ�б�ʾ���������R������C��1 <= R,C <= 100��
������R�У�ÿ����C������������߶�h�� 0<=h<=10000
Output:
��������ĳ���

Sample Input
5 5
1	2	3	4	5
16	17	18	19	6
15	24	25	20	7
14	23	22	21	8
13	12	11	10	9

Sample Output
25
*/


/*
�����������˼·���֣�
1.���ö�̬�滮�ı��� 
����ÿ����������·������
����ÿһ���������·�����̾���һ�����������Ž�Ĺ��� 
�ؼ�������⶯̬�滮�͵ݹ�Ĺ�ϵ 
*/
/*
#include <iostream>
using namespace std;

int data[102][102], longest[102][102];
int m, n;

int cal(int i, int j)
{
	int max = 0;   //������Χ�ڵ����󳤶ȣ�����������ı���
	if(longest[i][j] > 0)
		return longest[i][j]; 
	if(i-1 >= 0 && data[i][j] > data[i-1][j] && max < cal(i-1, j)) 
		max = cal(i-1, j);
	if(j-1 >= 0 && data[i][j] > data[i][j-1] && max < cal(i, j-1))
		max = cal(i, j-1);
	if(i+1 < m && data[i][j] > data[i+1][j] && max < cal(i+1, j))
		max = cal(i+1, j);
	if(j+1 < n && data[i][j] > data[i][j+1] && max < cal(i, j+1))
		max = cal(i, j+1);
	return longest[i][j] = max+1; 
} 

int main()
{
	int i, j;
	int maxway=0;
	
	cin>>m>>n;
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
		{
			cin>>data[i][j];
			longest[i][j] = 0; 
		} 
	
	for(i=0; i<m; i++)
		for(j=0; j<m; j++)
		{
			longest[i][j] = cal(i, j);
			if(maxway < longest[i][j])
				maxway = longest[i][j]; 
		} 
	cout<<maxway<<endl;
	return 0;
} 
*/

//2.����������ȱ���

#include <iostream>
#include <cstring>

using namespace std;

int data[102][102], longest[102][102];
int m, n;

int max4(int a, int b, int c, int d)
{
	if(a < b)
	   a = b;
	if(a < c)
	   a = c;
	if(a < d)
	   a = d;
	 
	return a; 
} 

int dft(int i, int j, int height)
{
	if(data[i][j] == -1 || height <= data[i][j])
		return 0;
	if(longest[i][j] > 0)
		return longest[i][j];
	longest[i][j] = max4(dft(i-1, j, data[i][j]), dft(i, j-1, data[i][j]), dft(i+1, j, data[i][j]), dft(i, j+1, data[i][j])) + 1;
	return longest[i][j]; 
}

int main()
{
	int i, j;
	int maxway = 0;
	
	memset(longest, -1, sizeof(longest));  //��longest�����е�����Ԫ����-1�滻 
	memset(data, -1, sizeof(data)); 
	
	cin>>m>>n;
	for(i=1; i!=m+1; i++)
		for(j=1; j!=n+1; j++)
			cin>>data[i][j];
			
    for(i=1; i!=m+1; i++)
		for(j=1; j!=n+1; j++)
		{
			longest[i][j] = dft(i, j, data[i][j]+1);
			if(maxway < longest[i][j])
				maxway = longest[i][j];		
	
		} 
	cout<<maxway<<endl;
	return 0; 
} 
