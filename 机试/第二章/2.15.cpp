#include <stdio.h>
#include <algorithm>
using namespace std;
struct program  //���ӽ�Ŀ�ṹ��
{
	int startTime;//��Ŀ��ʼʱ��
	int endTime;//��Ŀ����ʱ��
	bool operator<(const program &A)const //����С�ںţ���֤sort�����ܹ����ս���ʱ����������
	{
		return endTime<A.endTime;
	} 
} buf[100];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		  break;
		for(int i=0;i<n;i++)
			scanf("%d%d",&buf[i].startTime,&buf[i].endTime);//���� 
		sort(buf,buf+n);//���ս���ʱ����������
		int currentTime=0,ans=0;//��¼��ǰʱ�������ʼֵΪ0���𰸼�����ʼֵΪ0
		for(int i=0;i<n;i++)//���ս���ʱ������������еĽ�Ŀ
			if(currentTime<=buf[i].startTime)//����ǰʱ��С�ڵ��ڸý�Ŀ��ʼʱ�䣬��ô�տ�����ʣ���Ŀ�����ʱ������Ľ�Ŀ
			{
				currentTime=buf[i].endTime;//��ǰʱ���Ϊ�ý�Ŀ����ʱ��
				ans++;//���տ���һ����Ŀ 
			} 
		printf("%d\n",ans);//���
	}
	return 0;
}
