#include <stdio.h>
int main()
{
	int a,b;//�������������ı���
	while(scanf("%d%d",&a,&b)!=EOF)//������������
	{
		int buf1[20],buf2[20],size1=0,size2=0;//��buf1��buf2�ֱ𱣴�����������в���������λ���֣���������size1��size2��ʾ
		while(a!=0)//��λ��⣬ֻҪ��a��Ȼ������Ͳ����ظ�������
		{
			buf1[size1++]=a%10;//ȡ�õ�ǰ��λ�ϵ����֣����䱣��
			a/=10;//��������λ�ϵ������ƶ�����һλ�� 
		} 
		while(b!=0)//���ڶ�������
		{
			buf2[size2++]=b%10;
			b/=10;
		}
		int ans=0;//�����
		for(int i=0;i<size1;i++)
			for(int j=0;j<size2;j++)
				ans+=buf1[i]*buf2[j]; //������˺����
		printf("%d\n",ans); 
	} 
	return 0;
}
