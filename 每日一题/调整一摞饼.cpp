//http://blog.csdn.net/yangtrees/article/details/8237292

#include <iostream>
#include <cassert>
#include <cstdio>

using namespace std;

class laobing
{
private:
	int* m_CakeArray;  	//�ӱ���Ϣ����
	int m_nCakeCnt;     //�ӱ�����
	int m_nMaxSwap;     //��ཻ�����������Ϊm_nCakeCnt * 2
	int* m_SwapArray;   //�����������
	int* m_ReverseCakeArray;   //��ǰ��ת�ӱ���Ϣ����
	int* m_ReverseCakeArraySwap;    //��ǰ��ת�ӱ������������
	int m_nSearch;      //��ǰ����������Ϣ
	
public:
	laobing()
	{
		m_nCakeCnt = 0;
		m_nMaxSwap = 0;
	} 
	~laobing()
	{
		if(m_CakeArray != NULL)
			delete m_CakeArray;
		if(m_SwapArray != NULL)
			delete m_SwapArray;
		if(m_ReverseCakeArray != NULL)
			delete m_ReverseCakeArray;
		if(m_ReverseCakeArraySwap != NULL)
			delete m_ReverseCakeArraySwap; 
	} 
	
	void Run(int* pCakeArray, int nCakeCnt) //�����ӱ���ת��Ϣ  pCakeArray�洢�ӱ���������  nCakeCnt�ӱ�����
	{
		Init(pCakeArray, nCakeCnt);
		m_nSearch = 0;
		Search(0); 
	} 
	void mOutput(int* CakeArray, int nCakeCnt, int* m_SwapArray, int m_nMaxSwap)
	{
		int t;
		for(int i=0; i<m_nMaxSwap; i++)  //swap times
		{
			for(int j1=0,j2=m_SwapArray[i]; j1<j2; j1++,j2--)  //reverse array
			{
				t = CakeArray[j1];
				CakeArray[j1] = CakeArray[j2];
				CakeArray[j2] = t; 
			} 
			for(int k=0; k<nCakeCnt; ++k)
				printf("%d ", CakeArray[k]);
			printf("\n"); 
		} 
	} 
	void Output()   //����ӱ����巭ת�Ĵ���
	{
		for(int i=0; i<m_nMaxSwap; i++)
			printf("%d ", m_SwapArray[i]);
		
		printf("\n|Search Times| : %d\n", m_nSearch);
		printf("Total Swap times = %d\n", m_nMaxSwap);
		
		mOutput(m_CakeArray, m_nCakeCnt, m_SwapArray, m_nMaxSwap);  //����������� 
	} 
	
private:
	void Init(int* pCakeArray, int nCakeCnt)  //��ʼ��������Ϣ pCakeArray�洢�ӱ��������� nCakeCnt�ӱ�����
	{
		assert(pCakeArray != NULL);
		assert(nCakeCnt > 0);
		
		m_nCakeCnt = nCakeCnt;
		
		//��ʼ���ӱ�����
		m_CakeArray = new int[m_nCakeCnt];
		assert(m_CakeArray != NULL);
		for(int i=0; i<m_nCakeCnt; i++)
			m_CakeArray[i] = pCakeArray[i];
		
		m_nMaxSwap = UpBound(m_nCakeCnt);   //������ཻ��������Ϣ
		
		//��ʼ������������� 
		m_SwapArray = new int[m_nMaxSwap+1];
		assert(m_SwapArray != NULL);
		
		//��ʼ���м佻�������Ϣ
		m_ReverseCakeArray = new int[m_nCakeCnt];
		for(int i=0; i<m_nCakeCnt; i++)
			m_ReverseCakeArray[i] = m_CakeArray[i];
		m_ReverseCakeArraySwap = new int[m_nMaxSwap]; 
	} 
	
	int UpBound(int nCakeCnt)    //Ѱ�ҵ�ǰ��ת���Ͻ�
	{
		return nCakeCnt*2;
	} 
	
	int LowerBound(int* pCakeArray, int nCakeCnt)  //Ѱ�ҵ�ǰ��ת���½�
	{
		int t, ret = 0;
		
		//���ݵ�ǰ�����������Ϣ������ж�������Ҫ�������ٴ�
		for(int i=1; i<nCakeCnt; i++)
		{
			//�ж�λ�����ڵ������ӱ����Ƿ�Ϊ�ߴ��������ڵ� 
			t = pCakeArray[i] - pCakeArray[i-1];
			if((t == 1) || (t == -1))
			 ; 
			else
				ret++; 
		} 
		if(pCakeArray[nCakeCnt-1] != nCakeCnt-1)
			ret++; 
		return ret;
	} 
	void Search(int step)   //�����������
	{
		int i, nEstimate;
		m_nSearch++;
		
		nEstimate = LowerBound(m_ReverseCakeArray, m_nCakeCnt);   //���������������Ҫ����С��������
		if(step + nEstimate >= m_nMaxSwap)
			return ;
			
		if(IsSorted(m_ReverseCakeArray, m_nCakeCnt))  //����Ѿ��ź��򣬼���ת��ɣ������� 
		{
			if(step < m_nMaxSwap)
			{
				m_nMaxSwap = step;
				for(i=0; i<m_nMaxSwap; i++)
					m_SwapArray[i] = m_ReverseCakeArraySwap[i]; 
			} 
			return ;
		} 
		 
		 //�ݹ���з�ת
		 for(i=1; i<m_nCakeCnt; i++)
		 {
		 	Revert(0, i);  //��ת
			m_ReverseCakeArraySwap[step] = i;   //��һ����ת����һ��
			Search(step+1);
			Revert(0, i); 
		 } 
	} 
	
	bool IsSorted(int* pCakeArray, int nCakeCnt)  //true�Ѿ��ź���  falseδ����
	{
		for(int i=1; i<nCakeCnt; i++)
			if(pCakeArray[i-1] > pCakeArray[i])
				return false;
				
		return true; 
	} 
	void Revert(int nBegin, int nEnd)  //��ת�ӱ���Ϣ
	{
		assert(nEnd > nBegin);
		int i, j, t;
		
		//��ת�ӱ���Ϣ
		for(i=nBegin, j=nEnd; i<j; i++,j--)
		{
			t = m_ReverseCakeArray[i];
			m_ReverseCakeArray[i] = m_ReverseCakeArray[j];
			m_ReverseCakeArray[j] = t; 
		} 
	} 
};

int main()
{
	laobing ll;  //����ll�����Լ�����
	laobing* l = new laobing();
	int aa[10] = {3,2,1,6,5,4,9,8,7,0};
	l->Run(aa, 10);
	l->Output();
	
	ll.Run(aa, 10);
	return 0; 
} 
