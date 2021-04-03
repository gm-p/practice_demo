#include <stdio.h>
#include <vector>
#include <map>//要使用map，必须包含此头文件
#include <string>
#include <queue>
using namespace std;//声明使用标准命名空间
map<string,int> M;//定义一个完成从string到int映射的map
int in[2002];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		for(int i=0;i<2*n;i++)//n组胜负关系，至多存在n个队伍
			in[i]=0;//初始化入度
		M.clear();//对map中的映射关系清空
		int idx=0;//下一个被映射的数字
		for(int i=0;i<n;i++)
		{
			char str1[50],str2[50];
			scanf("%s%s",str1,str2);//输入两个选手名称
			string a=str1,b=str2;//将字符串保存至string中
			int idxa,idxb;
			if(M.find(a)==M.end())//若map中尚无对该a的映射
			{
				idxa=idx;
				M[a]=idx++;//设定其映射为idx，并递增idx 
			} 
			else
				idxa=M[a];//否则，直接读出该映射
			if(M.find(b)==M.end())
			{
				idxb=idx;
				M[b]=idx++;
			} 
			else
				idxb=M[b];//确定b的映射，方法与a相同
			in[idxb]++;//b的入度递增 
		}
		int cnt=0;
		for(int i=0;i<idx;i++)//确定所有映射数字的入度，统计入度为0的个数
			if(in[i]==0)
				cnt++;
		puts(cnt==1?"Yes":"No");//若入度为0输出Yes，否则输出No 
	}
	return 0;
} 
