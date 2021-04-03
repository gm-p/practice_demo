#include <stdio.h>
char maze[101][101];//�����ͼ��Ϣ
bool mark[101][101];//Ϊͼ��ÿһ��������һ��״̬
int n,m;//��ͼ��СΪn*m
int go[][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,-1,-1,1};//�˸����ڵ��뵱ǰλ�õ������
void DFS(int x,int y)//�ݹ����������x��yֱ�ӻ������ڵ�@
{
	for(int i=0;i<8;i++)//�����˸����ڵ�
	{
		int nx=x+go[i][0];
		int ny=y+go[i][1];//����������
		if(nx<1||nx>n||ny<1||ny>m)
			continue;//���������ڵ�ͼ��
		if(maze[nx][ny]=='*')
			continue;//����λ�ò���@ 
		if(mark[nx][ny]==true)
			continue;//����λ���Ѿ��������
		mark[nx][ny]=true;//��Ǹ�λ��Ϊ�Ѿ�����
		DFS(nx,ny);//�ݹ��ѯ�������λ��ֱ�����ڵĵ� 
	} 
	return ;
} 
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",maze[i]+1);//��i�е�ͼ��Ϣ������maze[i][1]��maze[i][m]�� 
		}//����Ϊ��λ�����ͼ��Ϣ
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				mark[i][j]=false;//��ʼ������λ��Ϊδ������
		int ans=0;//��ʼ���������
		for(int i=1;i<=n;i++)
		 for(int j=1;j<=m;j++)//��˳�����ͼ������λ��
		 {
		 	if(mark[i][j]==true)
		 		continue;//����λ���ѱ���������
			if(maze[i][j]=='*')
				continue;//����λ�ò�Ϊ@������
			DFS(i,j);//�ݹ��������ֱ�ӻ������ڵ�@
			ans++;//�𰸵��� 
		 } 
		 printf("%d\n",ans);//��� 
	}
	return 0;
}
