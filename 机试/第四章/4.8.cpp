#include <stdio.h>
#include <math.h>
bool judge(int x)//�ж�һ�����Ƿ�Ϊ����
{
	if(x<=1)
		return false;//����С�ڵ���1���ز���
	int bound=(int)sqrt(x)+1;//����ö���Ͻ磬Ϊ��ֹdouble��ֵ�����ľ�����ʧ�����Բ��ø���ֵȡ�������ټ�1������Ը��ö��һ����Ҳ������ö��һ����
	for(int i=2;i<bound;i++)
		if(x%i==0)
			return false;//����ö����Щ���ܷ�����x��������ز�Ϊ����
	return true; //��������Ϊ���� 
} 
int main()
{
	int x;
	while(scanf("%d",&x)!=EOF)
		puts(judge(x)?"yes":"no");//���ݺ�������ֵ�����
	return 0; 
}
