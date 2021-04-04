#include <bits/stdc++.h>

using namespace std;

    string longestPalindrome1(string s) {
        if(s.empty())
            return "";
        int n = s.size();
        string s1 = "";
        for(int i=0; i<n; i++)
        {
			s1 += "#" ;
			s1 += s[i];
		}    
        s1 += "#";cout<<s1<<endl;
        n = s1.size();
        vector<int> RL(n, 0);
        int maxRight = 0;  
        int pos = 0;
        int maxRL = 0;
        int maxPos = 0;
        for(int i=0; i<n; i++)
        {
            if(i < maxRight)
                RL[i] = min(RL[2*pos - i], maxRight - i);
            else
                RL[i] = 1;
            
            while(i - RL[i] >= 0 && i + RL[i] < n && s1[i - RL[i]] == s1[i + RL[i]])
                RL[i]++;
            if(RL[i] + i - 1 > maxRight)
            {
                maxRight = RL[i] + i - 1;
                pos = i;
            }
            if(maxRL <= RL[i])
            {
                maxRL = RL[i];
                maxPos = i;
            }
        }
        return s.substr((maxPos - maxRL + 1)/2, maxRL - 1);
    }
string longestPalindrome(string s)
{
	int len = s.length();
	if (len < 1)
	{
		return "";
	}

	// 预处理
	string s1;
	for (int i = 0; i < len; i++)
	{
		s1 += "#";
		s1 += s[i];
	}
	s1 += "#";cout<<s1<<endl;

	len = s1.length();
	int MaxRight = 0;				// 当前访问到的所有回文子串，所能触及的最右一个字符的位置
	int pos = 0;					// MaxRight对应的回文串的对称轴所在的位置
	int MaxRL = 0;					// 最大回文串的回文半径
	int MaxPos = 0;					// MaxRL对应的回文串的对称轴所在的位置
	int* RL = new int[len];			// RL[i]表示以第i个字符为对称轴的回文串的回文半径
	memset(RL, 0, len * sizeof(int));
	for (int i = 0; i < len; i++)
	{
		if (i < MaxRight)
		{// 1) 当i在MaxRight的左边
			RL[i] = min(RL[2 * pos - i], MaxRight - i);
		}
		else
		{// 2) 当i在MaxRight的右边
			RL[i] = 1;
		}


		// 尝试扩展RL[i]，注意处理边界
		while (i - RL[i] >= 0  // 可以把RL[i]理解为左半径,即回文串的起始位不能小于0
			&& i + RL[i] < len // 同上,即回文串的结束位不能大于总长
			&& s1[i - RL[i]] == s1[i + RL[i]]// 回文串特性，左右扩展，判断字符串是否相同
			)
		{
			RL[i] += 1;
		}

		// 更新MaxRight, pos
		if (RL[i] + i - 1 > MaxRight)
		{
			MaxRight = RL[i] + i - 1;
			pos = i;
		}

		// 更新MaxRL, MaxPos
		if (MaxRL <= RL[i])
		{
			MaxRL = RL[i];
			MaxPos = i;
		}
	}
	return s.substr((MaxPos - MaxRL + 1) / 2, MaxRL - 1);
}
int main()
{
	cout<<longestPalindrome1("babad")<<endl;
	return 0;
}
