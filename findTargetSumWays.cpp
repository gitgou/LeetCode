#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto num : nums){
            sum += num;
        }

        int neg = (sum - target) / 2;
        if((sum - target) < 0 || (sum - target) % 2 != 0){
            return 0;
        }
        //dp[i][j] 前 i 个num 中相加等于 j 的组合个数
        vector<vector<int>> dp(nums.size(), vector<int>(neg + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= nums.size(); ++i){
            for(int j = 0; j <= neg; ++j){
                if(nums[i - 1] > j){
                    dp[i][j] = dp[i - 1][j];
                }else{
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[nums.size()][neg];
    }
};
