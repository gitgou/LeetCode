#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isVaild(int row, int col, int k){
        string sRow = to_string(row), sCol = to_string(col); 
        int sum = 0;
        for(int i = 0; i < sRow.size(); ++i){
            sum += sRow[i] - '0';
        }
        for(int i = 0; i < sCol.size(); ++i){
            sum += sCol[i] - '0';
        }

        return sum <= k;
    }
    int movingCount(int m, int n, int k) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 1;
        dp[0][0] = 1;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                bool valid = isVaild(i, j, k);
                if(i == 0 && j == 0 || ! valid)
                    continue;
            
                if(i-1 >= 0) dp[i][j] |= dp[i-1][j];
                if(j-1>=0)  dp[i][j] |= dp[i][j-1]; 
                if(dp[i][j])
                    res++;
            }
        }
        return res;
    }
    
};