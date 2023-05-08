#include<iostream>
#include<vector>
using namespace std;
//TODO
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        // n 天最多只能有 n /2 次交易
        int n = prices.size();
        k = min(k, n / 2);


        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(k+1, vector<int>(2, 0)));
        //第 1 天 k次买卖收益值
        for(int i = 0; i < k; ++i){
        }

        for(int i = 1; i < prices.size(); ++i){
            for(int j = 1; j < k; ++j){
            }
        }
    }
};
