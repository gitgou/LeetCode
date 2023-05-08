#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        dp[0][1] = -prices[0]; dp[0][0] = 0; dp[0][2] = 0; //持有 & 未持有 & 冷冻 
        for(int i = 1; i < prices.size(); ++i){
            dp[i][1] = std::max(dp[i-1][1], dp[i-1][2] -prices[i]);
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][2] = std::max(dp[i-1][2], dp[i-1][0]);
        }
        return dp[prices.size()-1][0];
    }
};