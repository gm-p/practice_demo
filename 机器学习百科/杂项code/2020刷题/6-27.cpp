#include <bits/stdc++.h>

using namespace std;

 int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return n;
        int i = 0, j = 1;
        int count = 1;
        while(j < n)
        {
            if(nums[i] == nums[j])
            {
				if(count < 2)
				{
					nums[++i] = nums[j];
				}
                count++;
                j++;
            }
            else if(count >= 2)
            {
                nums[++i] = nums[j];
                j++;
                count = 1;
            }
            else
            {
                nums[++i] = nums[j];
                j++;
                count = 1;
            }
        }
        return i+1;
    }
    
int main()
{
	vector<int> nums{1, 1, 1, 1, 2, 2, 3};
	int n = removeDuplicates(nums);
	for(int i=0; i<n; i++)
		cout<<nums[i]<<',';
	return 0;
}
