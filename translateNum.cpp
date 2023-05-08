#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string sNum = to_string(num);
        vector<int> dp(sNum.size() + 1, 0);
        dp[1] = 1;
        for(int i = 2; i <= sNum.size(); ++i){
            dp[i] = dp[i-1];
            int  tmp = (sNum[i-2] - '0') * 10 + (sNum[i-1] - '0');
            if(tmp < 26){
                dp[i] += dp[i-2];
            }
        }
        return dp[sNum.size()];
    }
};