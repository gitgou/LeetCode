#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1, dp[1] = 1;
        for(int i = 2; i <= s.size(); ++i){
            if(s[i] != '0')
                dp[i] = dp[i-1];
            int tmp = (s[i-2] - '0' ) * 10 + (s[i-1] - '0');
            if(tmp <= 26 && tmp >= 10){
                dp[i] += dp[i-2];
            }  
        }
        return dp[n];
    }
};