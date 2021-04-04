//http://blog.csdn.net/yangtrees/article/details/8237292

#include <iostream>
#include <cassert>
#include <cstdio>

using namespace std;

class laobing
{
private:
	int* m_CakeArray;  	//烙饼信息数组
	int m_nCakeCnt;     //烙饼个数
	int m_nMaxSwap;     //最多交换次数，最多为m_nCakeCnt * 2
	int* m_SwapArray;   //交换结果数组
	int* m_ReverseCakeArray;   //当前翻转烙饼信息数组
	int* m_ReverseCakeArraySwap;    //当前翻转烙饼交换结果数组
	int m_nSearch;      //当前搜索次数信息
	
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
	
	void Run(int* pCakeArray, int nCakeCnt) //计算烙饼翻转信息  pCakeArray存储烙饼索引数组  nCakeCnt烙饼个数
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
	void Output()   //输出烙饼具体翻转的次数
	{
		for(int i=0; i<m_nMaxSwap; i++)
			printf("%d ", m_SwapArray[i]);
		
		printf("\n|Search Times| : %d\n", m_nSearch);
		printf("Total Swap times = %d\n", m_nMaxSwap);
		
		mOutput(m_CakeArray, m_nCakeCnt, m_SwapArray, m_nMaxSwap);  //输出交换过程 
	} 
	
private:
	void Init(int* pCakeArray, int nCakeCnt)  //初始化数组信息 pCakeArray存储烙饼索引数组 nCakeCnt烙饼个数
	{
		assert(pCakeArray != NULL);
		assert(nCakeCnt > 0);
		
		m_nCakeCnt = nCakeCnt;
		
		//初始化烙饼数组
		m_CakeArray = new int[m_nCakeCnt];
		assert(m_CakeArray != NULL);
		for(int i=0; i<m_nCakeCnt; i++)
			m_CakeArray[i] = pCakeArray[i];
		
		m_nMaxSwap = UpBound(m_nCakeCnt);   //设置最多交换次数信息
		
		//初始化交换结果数组 
		m_SwapArray = new int[m_nMaxSwap+1];
		assert(m_SwapArray != NULL);
		
		//初始化中间交换结果信息
		m_ReverseCakeArray = new int[m_nCakeCnt];
		for(int i=0; i<m_nCakeCnt; i++)
			m_ReverseCakeArray[i] = m_CakeArray[i];
		m_ReverseCakeArraySwap = new int[m_nMaxSwap]; 
	} 
	
	int UpBound(int nCakeCnt)    //寻找当前翻转的上界
	{
		return nCakeCnt*2;
	} 
	
	int LowerBound(int* pCakeArray, int nCakeCnt)  //寻找当前翻转的下界
	{
		int t, ret = 0;
		
		//根据当前数组的排序信息情况来判断最少需要交换多少次
		for(int i=1; i<nCakeCnt; i++)
		{
			//判断位置相邻的两个烙饼，是否为尺寸排序相邻的 
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
	void Search(int step)   //排序的主函数
	{
		int i, nEstimate;
		m_nSearch++;
		
		nEstimate = LowerBound(m_ReverseCakeArray, m_nCakeCnt);   //估算这次搜索所需要的最小交换次数
		if(step + nEstimate >= m_nMaxSwap)
			return ;
			
		if(IsSorted(m_ReverseCakeArray, m_nCakeCnt))  //如果已经排好序，即翻转完成，输出结果 
		{
			if(step < m_nMaxSwap)
			{
				m_nMaxSwap = step;
				for(i=0; i<m_nMaxSwap; i++)
					m_SwapArray[i] = m_ReverseCakeArraySwap[i]; 
			} 
			return ;
		} 
		 
		 //递归进行翻转
		 for(i=1; i<m_nCakeCnt; i++)
		 {
		 	Revert(0, i);  //反转
			m_ReverseCakeArraySwap[step] = i;   //第一步反转的哪一个
			Search(step+1);
			Revert(0, i); 
		 } 
	} 
	
	bool IsSorted(int* pCakeArray, int nCakeCnt)  //true已经排好序  false未排序
	{
		for(int i=1; i<nCakeCnt; i++)
			if(pCakeArray[i-1] > pCakeArray[i])
				return false;
				
		return true; 
	} 
	void Revert(int nBegin, int nEnd)  //翻转烙饼信息
	{
		assert(nEnd > nBegin);
		int i, j, t;
		
		//翻转烙饼信息
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
	laobing ll;  //这里ll不可以加括号
	laobing* l = new laobing();
	int aa[10] = {3,2,1,6,5,4,9,8,7,0};
	l->Run(aa, 10);
	l->Output();
	
	ll.Run(aa, 10);
	return 0; 
} 
