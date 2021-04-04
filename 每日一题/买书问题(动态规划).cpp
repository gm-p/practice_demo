//http://blog.csdn.net/yangtrees/article/details/8238467

#include <iostream>
#include <cstdlib>
//#include <random>
#include <cstring>

using namespace std;

#define random(x) (rand()%x)
const int large = 10000;
int countRE=0, countDP=0;  //利用动态规划能少递归多少次， 计数
double S[10][10][10][10][10];

template<typename T>
void reRank(T m[], int length)  //insert sort
{
	for(int i=1; i<length; i++) 
	{
		T tmp = m[i];
		int j;
		for(j=i-1; j>=0 && tmp<m[j]; j--)
			m[j+1] = m[j];
		m[j+1] = tmp; 
	} 
} 

double findMin(double t1, double t2, double t3, double t4, double t5)
{
	double n[5] = {t1, t2, t3, t4, t5};
	reRank(n, 5);
	return n[0]; 
} 

double BestBuy(int x1, int x2, int x3, int x4, int x5)
{
	countRE++;
	int i;
	int n[5] = {x1, x2, x3, x4, x5};
	reRank(n, 5);
	x1 = n[0];
	x2 = n[1];
	x3 = n[2];
	x4 = n[3];
	x5 = n[4];
	if(S[x1][x2][x3][x4][x5] > 0)
		return S[x1][x2][x3][x4][x5];
	countDP++;
	if(n[0] > 0)
	{
		double solution = findMin(8+BestBuy(x1, x2, x3, x4, x5-1),
								2*8*0.95 + BestBuy(x1, x2, x3, x4-1, x5-1),
								3*8*0.9 + BestBuy(x1, x2, x3-1, x4-1, x5-1),
								4*8*0.8 + BestBuy(x1, x2-1, x3-1, x4-1, x5-1),
								5*8*0.75 + BestBuy(x1-1, x2-1, x3-1, x4-1, x5-1));
		S[x1][x2][x3][x4][x5] = solution;
		return solution;
	} 
	else if((n[0] == 0) && (n[1] > 0))
	{
		double solution = findMin(8 + BestBuy(x1, x2, x3, x4, x5-1),
								 2*8*0.95 + BestBuy(x1, x2, x3, x4-1, x5-1),
								 3*8*0.9 + BestBuy(x1, x2, x3-1, x4-1, x5-1),
								 4*8*0.8 + BestBuy(x1, x2-1, x3-1, x4-1, x5-1),
								 large);
		S[x1][x2][x3][x4][x5] = solution;
		return solution; 
	} 
	else if((n[0] == 0) && (n[1] == 0) && (n[2] > 0))
	{
		double solution = findMin(8 + BestBuy(x1, x2, x3, x4, x5-1),
								  2*8*0.95 + BestBuy(x1, x2, x3, x4-1, x5-1),
								  3*8*0.9 + BestBuy(x1, x2, x3-1, x4-1, x5-1),
								  large, large);
		S[x1][x2][x3][x4][x5] = solution;
		return solution; 
	} 
	else if((n[0] == 0) && (n[1] == 0) && (n[2] == 0) && (n[3] > 0))
	{
		double solution = findMin(8 + BestBuy(x1, x2, x3, x4, x5-1),
								 2*8*0.95 + BestBuy(x1, x2, x3, x4-1, x5-1),
								 large, large, large);
		S[x1][x2][x3][x4][x5] = solution;
		return solution; 
	} 
	else if((n[0] == 0) && (n[1] == 0) && (n[2] == 0) && (n[3] == 0) && (n[4] > 0))
	{
		double solution = findMin(8 + BestBuy(x1, x2, x3, x4, x5-1),
								 large, large, large, large);
		S[x1][x2][x3][x4][x5] = solution;
		return solution; 
	} 
	else 
	{
		S[x1][x2][x3][x4][x5] = 0;
		return 0; 
	} 
} 

int main()
{
	int N = 5;
	int a[10];
	memset(S, 0, sizeof(S));
	for(int i=0; i<N; i++)
	{
		a[i] = random(10);
		cout<<a[i]<<" "; 
	} 
	cout<<endl;
	cout<<BestBuy(a[0], a[1], a[2], a[3], a[4])<<endl;
	for(int i=0; i<N; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<"递归次数： "<<countRE<<endl;
	cout<<"动态规划 递归计算次数： "<<countDP<<endl;
	return 0; 
} 

//C++新特性，头文件通不过，可以用在线编译器编译 ：http://ideone.com/LlluiI 
