#include <stdio.h>
int gcd(int a,int b)
{
	if(b==0)
		return a;//��bΪ�������Լ��Ϊa
	else
		return gcd(b,a%b);//�������Ϊ��b��a%b�����Լ�� 
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)//��������������
		printf("%d\n",gcd(a,b));//�����������Լ��
	return 0; 
}
