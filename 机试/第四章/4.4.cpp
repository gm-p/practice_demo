#include <stdio.h>
#include <string.h>
int main()
{
	int a,b;
	char str[40];
	while(scanf("%d%s%d",&a,str,&b)!=EOF)
	{
		int tmp=0,length=strlen(str),c=1;//tmpΪ���ǽ�Ҫ�����a���ƶ�Ӧ��ʮ��������lengthΪ�ַ������ȷ������Ǵӵ�λ����λ����
										//ÿ����λ�ϵ�����cΪ������λ��Ȩ�س�ʼ��Ϊ1����ʾ��λ��λȨ��Ϊ1��֮��ÿλȨ�ض���ǰһλȨ�ص�a��
		 for(int i=length-1;i>=0;i--)//�ӵ�λ����λ����ÿ����λ�ϵ���
		 {
		 	int x;//�����λ������
			if(str[i]>='0'&&str[i]<='9')
				x=str[i]-'0';//���ַ���0��9֮�䣬��������������
			else if(str[i]>='a'&&str[i]<='z') 
				x=str[i]-'a'+10;//���ַ�ΪСд��ĸʱ����������������
			else
				x=str[i]-'A'+10;//���ַ�Ϊ��д��ĸʱ����������������
			tmp+=x*c;//�ۼӸ�λ���������λȨ�صĻ�
			c*=a;//������һλ��λȨ�� 
		 } 
		 char ans[40],size=0;//��ans����ת����b���Ƶĸ�����λ����
		 do
		 {
		 	int x=tmp%b;//�����λ����
			ans[size++]=(x<10)?x+'0':x-10+'A';//������ת��Ϊ�ַ�
			tmp/=b; 
		 } while(tmp);
		 for(int i=size-1;i>=0;i--)
		 	printf("%c",ans[i]);
		printf("\n");//��� 
	}
	return 0;
}
