#include <stdio.h>
char maze[8][8];//�����ͼ��Ϣ
int n,m,t;//��ͼ��СΪn*m,����㵽�յ��ܷ�ǡ��t��
bool success;//�Ƿ��ҵ�����Ҫ״̬���
int go[][2]={1,0,-1,0,0,1,0,-1};//�ķ������������
void DFS(int x,int y,int time)//�ݹ���ʽ�������������
{
	for(int i=0;i<4;i++)//ö���ĸ�����λ��
	{
		int nx=x+go[i][0];
		int ny=y+go[i][1];//����������
		if(nx<1||nx>n||ny<1||ny>m)
			continue;//�������ڵ�ͼ��������
		if(maze[nx][ny]=='X')
			continue;//����λ��Ϊǽ������
		if(maze[nx][ny]=='D')//����λ��Ϊ��
		{
			if(time+1==t)//������ʱ��ǡ��Ϊt
			{
				success=true;//�����ɹ�
				return ;//���� 
			} 
			else
				continue;//�����״̬�ĺ���״̬������Ϊ�𰸣������ĵ㲻���پ����������� 
		} 
		maze[nx][ny]='X';//��״̬��չ�����ĺ���״̬�У���λ�ö����ܱ�������ֱ���޸ĸ�λ��Ϊǽ
		DFS(nx,ny,time+1);//�ݹ���չ��״̬������ʱ����� 
		maze[nx][ny]='.';//�������״̬ȫ��������ϣ����˻��ϲ�״̬������ΪҪ���������״̬���ĳ�ǽ��λ�ã��Ļ���ͨλ��
		if(success)
			return ;//�ٶ��Ѿ��ɹ�����ֱ�ӷ��أ�ֹͣ���� 
	} 
} 
int main()
{
	while(scanf("%d%d%d",&n,&m,&t)!=EOF)
	{
		if(n==0&&m==0&&t==0)
			break;
		for(int i=1;i<=n;i++)
			scanf("%s",maze[i]+1);//����
		success=false;//��ʼ���ɹ����
		int sx,sy;
		for(int i=1;i<=n;i++)//Ѱ��D��λ������
			for(int j=1;j<=m;j++)
				if(maze[i][j]=='D')
				 {
				 	sx=i;
				 	sy=j;
				 }
		for(int i=1;i<=n;i++)//Ѱ�ҳ���״̬
			for(int j=1;j<=m;j++)
				if(maze[i][j]=='S'&&(i+j)%2==((sx+sy)%2+t%2)%2)//�ҵ�S������ж�S��D����ż�Թ�ϵ���Ƿ��t���ϣ���������ʽ����������ֱ����������
				{
					maze[i][j]='X';//�������Ϊǽ
					DFS(i,j,0);//�ݹ���չ����״̬ 
				}
		puts(success==true?"YES":"NO");//��successΪ�棬�����yes 
	}
	return 0;
}

