#include <stdio.h>
#include <string.h>
struct bigInteger
{
	int digit[1000];
	int size;
	void init()//��ʼ��
	{
		for(int i=0;i<1000;i++)
			digit[i]=0;
		size=0;
	} 
	void set(int x)//��һ��С�������ø߾�������
	{
		init();
		do//��С����4λΪһ����λ�ֽ����δ���digit����
		{
			digit[size++]=x%10000;
			x/=10000;
		}while(x!=0);
	} 
	void output()//���
	{
		for(int i=size-1;i>=0;i--)
		{
			if(i!=size-1)
				printf("%04d",digit[i]);
			else
				printf("%d",digit[i]);
		}
		printf("\n");
	} 
	bigInteger operator*(int x)const//�˷������
	{
		bigInteger ret;//��Ҫ���صĸ߾�������
		ret.init();//��ʼ��
		int carry=0;//��λ��ʼֵΪ0
		for(int i=0;i<size;i++)
		{
			int tmp=x*digit[i]+carry;//��С����x���Ե�ǰ���ֲ��������Ե�λ�Ľ�λ
			carry=tmp/10000;//�����λ
			ret.digit[ret.size++]=tmp;//�����λ���� 
		} 
		if(carry!=0)//�����λ�н�λ
			ret.digit[ret.size++]=carry;//����ý�λ 
		return ret;
	} 
}a;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		a.init();//��ʼ��a
		a.set(1);//a��ʼֵΪ1
		for(int i=1;i<=n;i++)
			a=a*i;//���γ���ÿһ������
		 a.output();//���a 
	}
	return 0;
}
