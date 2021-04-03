#include <stdio.h>
#include <string.h>
struct Node//二叉树结构体
{
	Node *lchild;//左儿子指针
	Node *rchild;//右儿子指针
	int c;//保存数字 
}Tree[110];//静态数组
int Ioc;//静态数组中被使用元素个数
Node *creat()//申请未使用的结点
{
	Tree[Ioc].lchild=Tree[Ioc].rchild=NULL;
	return &Tree[Ioc++];
} 
void postOrder(Node *T)//后序遍历
{
	if(T->lchild!=NULL)
		postOrder(T->lchild);
	if(T->rchild!=NULL)
		postOrder(T->rchild);
	printf("%d ",T->c); 
} 
void InOrder(Node *T)//中序遍历
{
	if(T->lchild!=NULL)
		InOrder(T->lchild);
	printf("%d ",T->c);
	if(T->rchild!=NULL)
		InOrder(T->rchild); 
}
void preOrder(Node *T)//前序遍历
{
	printf("%d ",T->c);
	if(T->lchild!=NULL)
		preOrder(T->lchild);
	if(T->rchild!=NULL)
		preOrder(T->rchild);
} 
Node *Insert(Node *T,int x) //插入数字
{
	if(T==NULL)//若当前树为空
	{
		T=creat();//建立结点
		T->c=x;//数字直接插入其根节点
		return T; 
	} 
	else if(x< T->c)//若x小于根节点数值
		T->lchild=Insert(T->lchild,x);//插入到左子树上
	else if(x> T->c)//若x大于根节点数值
		T->rchild=Insert(T->rchild,x);//插入到右子树，若根节点数值与x一样，根据题目要求直接忽略
		return T;//返回根节点指针 
} 
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		Ioc=0;
		Node *T=NULL;//二叉排序树根节点为空
		for(int i=0;i<n;i++)//依次输入n个数字
		{
			int x;
			scanf("%d",&x);
			T=Insert(T,x);//插入到排序树中 
		} 
		preOrder(T);//前序遍历
		printf("\n");//输出换行
		InOrder(T);//中序遍历
		printf("\n");
		postOrder(T);//后序遍历
		printf("\n"); 
	}
	return 0;
}
