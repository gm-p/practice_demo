#include <stdio.h>
#include <vector>
#include <map>//Ҫʹ��map�����������ͷ�ļ�
#include <string>
#include <queue>
using namespace std;//����ʹ�ñ�׼�����ռ�
map<string,int> M;//����һ����ɴ�string��intӳ���map
int in[2002];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		for(int i=0;i<2*n;i++)//n��ʤ����ϵ���������n������
			in[i]=0;//��ʼ�����
		M.clear();//��map�е�ӳ���ϵ���
		int idx=0;//��һ����ӳ�������
		for(int i=0;i<n;i++)
		{
			char str1[50],str2[50];
			scanf("%s%s",str1,str2);//��������ѡ������
			string a=str1,b=str2;//���ַ���������string��
			int idxa,idxb;
			if(M.find(a)==M.end())//��map�����޶Ը�a��ӳ��
			{
				idxa=idx;
				M[a]=idx++;//�趨��ӳ��Ϊidx��������idx 
			} 
			else
				idxa=M[a];//����ֱ�Ӷ�����ӳ��
			if(M.find(b)==M.end())
			{
				idxb=idx;
				M[b]=idx++;
			} 
			else
				idxb=M[b];//ȷ��b��ӳ�䣬������a��ͬ
			in[idxb]++;//b����ȵ��� 
		}
		int cnt=0;
		for(int i=0;i<idx;i++)//ȷ������ӳ�����ֵ���ȣ�ͳ�����Ϊ0�ĸ���
			if(in[i]==0)
				cnt++;
		puts(cnt==1?"Yes":"No");//�����Ϊ0���Yes���������No 
	}
	return 0;
} 
