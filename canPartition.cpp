#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums){
            sum += num;
        }
        if(sum % 2 != 0){
            return false;
        }

        int target = sum / 2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, false));
        dp[0][0] = true; //前 i 个是否有组合等于 j 
        dp[0][nums[0]] = true;
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j <= target; ++j){
                dp[i][j] = dp[i - 1][j];
                if(j >= nums[i])
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
            }
        }

        return dp[nums.size() - 1][target];    
    }
};