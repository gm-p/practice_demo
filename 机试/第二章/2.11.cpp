#include <stdio.h>
int main()
{
	int outPutBuf[82][82];//����Ԥ�Ű���������
	char a,b;//����������ַ�
	int n;//�����С
	bool firstCase=true;//�Ƿ�Ϊ��һ�����ݱ�־����ʼֵΪtrue
	while(scanf("%d %c %c",&n,&a,&b)==3)
	{
		if(firstCase==true)//���ǵ�һ������
		  firstCase=false;//����һ�����ݱ�־��ǳ�false
		else
		  printf("\n");//�����������
		for(int i=1,j=1;i<=n;i+=2,j++)//�����������ÿ��Ȧ 
		{
			int x=n/2+1,y=x;
			x-=j-1;  y-=j-1;//����ÿ��Ȧ���Ͻǵ������
			char c=j%2==1?a:b;//���㵱ǰȦ��Ҫʹ���ĸ��ַ� 
			for(int k=1;k<=i;k++)//�Ե�ǰȦ���и�ֵ
			{
				outPutBuf[x+k-1][y]=c;//��߸�ֵ
				outPutBuf[x][y+k-1]=c;//�ϱ߸�ֵ
				outPutBuf[x+i-1][y+k-1]=c;//�ұ߸�ֵ
				outPutBuf[x+k-1][y+i-1]=c;//�±߸�ֵ 
			} 
		} 
		if(n!=1)//ע�⵱nΪ1ʱ����˲���
		{
			outPutBuf[1][1]=' ';
			outPutBuf[n][1]=' ';
			outPutBuf[1][n]=' ';
			outPutBuf[n][n]=' ';//���Ľ���Ϊ�ո� 
		} 
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			  printf("%c",outPutBuf[i][j]);
			printf("\n");
		}//����Ѿ������Ű������������е����� 
	} 
	return 0;
}
