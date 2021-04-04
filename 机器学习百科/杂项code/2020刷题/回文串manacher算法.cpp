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

	// Ԥ����
	string s1;
	for (int i = 0; i < len; i++)
	{
		s1 += "#";
		s1 += s[i];
	}
	s1 += "#";cout<<s1<<endl;

	len = s1.length();
	int MaxRight = 0;				// ��ǰ���ʵ������л����Ӵ������ܴ���������һ���ַ���λ��
	int pos = 0;					// MaxRight��Ӧ�Ļ��Ĵ��ĶԳ������ڵ�λ��
	int MaxRL = 0;					// �����Ĵ��Ļ��İ뾶
	int MaxPos = 0;					// MaxRL��Ӧ�Ļ��Ĵ��ĶԳ������ڵ�λ��
	int* RL = new int[len];			// RL[i]��ʾ�Ե�i���ַ�Ϊ�Գ���Ļ��Ĵ��Ļ��İ뾶
	memset(RL, 0, len * sizeof(int));
	for (int i = 0; i < len; i++)
	{
		if (i < MaxRight)
		{// 1) ��i��MaxRight�����
			RL[i] = min(RL[2 * pos - i], MaxRight - i);
		}
		else
		{// 2) ��i��MaxRight���ұ�
			RL[i] = 1;
		}


		// ������չRL[i]��ע�⴦��߽�
		while (i - RL[i] >= 0  // ���԰�RL[i]���Ϊ��뾶,�����Ĵ�����ʼλ����С��0
			&& i + RL[i] < len // ͬ��,�����Ĵ��Ľ���λ���ܴ����ܳ�
			&& s1[i - RL[i]] == s1[i + RL[i]]// ���Ĵ����ԣ�������չ���ж��ַ����Ƿ���ͬ
			)
		{
			RL[i] += 1;
		}

		// ����MaxRight, pos
		if (RL[i] + i - 1 > MaxRight)
		{
			MaxRight = RL[i] + i - 1;
			pos = i;
		}

		// ����MaxRL, MaxPos
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
