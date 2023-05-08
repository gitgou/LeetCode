#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), nums.size() + 1);
        dp[0] = 0;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 1; j <= nums[i]; ++j){
                if(i+j < nums.size())
                    dp[i+j] = std::min(dp[i+j], dp[i] + 1);
            }
        }
        return dp[nums.size() - 1];
    }
};