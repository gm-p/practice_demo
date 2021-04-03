#include <stdio.h>
#include <string.h>
struct Node//�������ṹ��
{
	Node *lchild;//�����ָ��
	Node *rchild;//�Ҷ���ָ��
	int c;//�������� 
}Tree[110];//��̬����
int Ioc;//��̬�����б�ʹ��Ԫ�ظ���
Node *creat()//����δʹ�õĽ��
{
	Tree[Ioc].lchild=Tree[Ioc].rchild=NULL;
	return &Tree[Ioc++];
} 
void postOrder(Node *T)//�������
{
	if(T->lchild!=NULL)
		postOrder(T->lchild);
	if(T->rchild!=NULL)
		postOrder(T->rchild);
	printf("%d ",T->c); 
} 
void InOrder(Node *T)//�������
{
	if(T->lchild!=NULL)
		InOrder(T->lchild);
	printf("%d ",T->c);
	if(T->rchild!=NULL)
		InOrder(T->rchild); 
}
void preOrder(Node *T)//ǰ�����
{
	printf("%d ",T->c);
	if(T->lchild!=NULL)
		preOrder(T->lchild);
	if(T->rchild!=NULL)
		preOrder(T->rchild);
} 
Node *Insert(Node *T,int x) //��������
{
	if(T==NULL)//����ǰ��Ϊ��
	{
		T=creat();//�������
		T->c=x;//����ֱ�Ӳ�������ڵ�
		return T; 
	} 
	else if(x< T->c)//��xС�ڸ��ڵ���ֵ
		T->lchild=Insert(T->lchild,x);//���뵽��������
	else if(x> T->c)//��x���ڸ��ڵ���ֵ
		T->rchild=Insert(T->rchild,x);//���뵽�������������ڵ���ֵ��xһ����������ĿҪ��ֱ�Ӻ���
		return T;//���ظ��ڵ�ָ�� 
} 
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		Ioc=0;
		Node *T=NULL;//�������������ڵ�Ϊ��
		for(int i=0;i<n;i++)//��������n������
		{
			int x;
			scanf("%d",&x);
			T=Insert(T,x);//���뵽�������� 
		} 
		preOrder(T);//ǰ�����
		printf("\n");//�������
		InOrder(T);//�������
		printf("\n");
		postOrder(T);//�������
		printf("\n"); 
	}
	return 0;
}
