#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> vec(strs.size(), {0,0});
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(n + 1, vector<int>(m + 1, 0)));
        for(int i = 0; i < strs.size(); ++i){
            int ones = 0, zeros = 0;
            for(int j = 0; j < strs[i].size(); ++j){
                if(strs[i][j] == '0'){
                    zeros++;
                }else{
                    ones++;
                }
            }
            //cout << " i " << " ones: " << ones << " zeros " << zeros << endl;
            vec[i] = {ones, zeros};
            //cout << " vec " << vec[i].first << ", " << vec[i].second << endl;
        }
       
        for(int i = 1; i <= strs.size(); ++i){
            int ones = vec[i-1].first, zeros = vec[i-1].second;
            for(int j = 0; j <= n; ++j){
                for(int k = 0; k <= m; ++k){
                    dp[i][j][k] = dp[i - 1][j][k];
                    if(ones <= j && zeros <= k){
                        dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j - ones][k - zeros] + 1);
                        //cout << "dp " << i << " " << j << " " << " " << k << " " << dp[i][j][k] << endl;
                    }
                }
            }
        }

        return dp[strs.size()][n][m];
    }
};