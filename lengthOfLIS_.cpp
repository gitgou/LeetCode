#include<iostream>
#include<vector>

using namespace std;
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> dp(nums.size(), 0);
        int max = 1;
        for(int i = 0; i < nums.size(); ++i)
        {
            dp[i] = 1;
            for(int j = 0; j < i; ++j)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }

            }

            max = max < dp[i] ? dp[i] : max;
        }

        return max;
    }

int main()
{ 
    //error
    vector<int> vec{1,5,3,4, 5, 2, 7};
    cout << lengthOfLIS(vec) << endl;
    return 0;
}
