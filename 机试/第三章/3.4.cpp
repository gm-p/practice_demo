#include <stdio.h>
#include <string.h>
struct Node //�����ṹ��
{
	Node *lchild;//�����ָ��
	Node *rchild;//�Ҷ���ָ��
	char c;//����ַ���Ϣ 
}Tree[50];//��̬�ڴ��������
int Ioc;//��̬�������Ѿ�����Ľ�����
Node *creat()//����һ�����ռ䣬����ָ�����ָ��
{
	Tree[Ioc].lchild=Tree[Ioc].rchild=NULL;//��ʼ�����Ҷ���Ϊ��
	return &Tree[Ioc++];//����ָ�룬��Ioc�ۼ� 
} 
char str1[30],str2[30];//����ǰ��������������ַ���
void postOrder(Node *T) //�������
{
	if(T->lchild!=NULL)//����������Ϊ��
	  postOrder(T->lchild);//�ݹ������������
	if(T->rchild!=NULL)//����������Ϊ��
	  postOrder(T->rchild);//�ݹ������������
	printf("%c",T->c);//�����ý�㣬������ַ���Ϣ 
} 
Node *build(int s1,int e1,int s2,int e2)//���ַ�����ǰ����������������ԭ���������������㣬����ǰ��������Ϊ��str1[s1]��str1[e1],����������Ϊstr2[s2]��str2[e2]
{
	Node *ret=creat();//Ϊ�������������ռ�
	ret->c=str1[s1];//�ý���ַ�Ϊǰ������е�һ���ַ�
	int rootIdx;
	for(int i=s2;i<=e2;i++) //���Ҹø��ڵ��ַ�����������е�λ�� 
		if(str2[i]==str1[s1])
		{
			rootIdx=i;
			break;
		}
	if(rootIdx!=s2)//����������Ϊ��
		ret->lchild=build(s1+1,s1+(rootIdx-s2),s2,rootIdx-1);//�ݹ黹ԭ��������
	if(rootIdx!=e2)//����������Ϊ��
		ret->rchild=build(s1+(rootIdx-s2)+1,e1,rootIdx+1,e2);//�ݹ黹ԭ��������
	return ret;//���ظ��ڵ�ָ�� 
}
int main()
{
	while(scanf("%s",str1)!=EOF)
	{
		scanf("%s",str2);//����
		Ioc=0;//��ʼ����̬�ڴ�ռ����Ѿ�ʹ�ý�����Ϊ0
		int L1=strlen(str1);
		int L2=strlen(str2);//���������ַ������� 
		Node *T=build(0,L1-1,0,L2-1);//��ԭ������������ڵ�ָ�뱣����T��
		postOrder(T);//�������
		printf("\n");//������� 
	}
	return 0;
}
 
