#include<iostream>
#include<vector>
using namespace std;
//贪心
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};


/*
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(nums.size(), 0));
        dp[0][0] = true;
        for(int i = 1; i <= nums.size(); ++i){
            for(int j = 0; i < nums.size(); ++j){
                if(j == 0){
                    dp[i][j] = true;
                }else{
                    dp[i][j] = (dp[i - 1][j] || (dp[i-1][i - 1] && (nums[i - 1] >= j - i + 1)));
                }
            }
        }
        return dp[nums.size()][nums.size() - 1];
    }
};
*/