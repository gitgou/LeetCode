#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPalindromicSubsequences(string s) {
      //  先求回文子串
      int n = s.size();
      vector<vector<vector<int>>> dp(4, vector<vector<int>>(n, vector<int>(n, 0)));
      for(int i = 0; i < n; ++i){
        dp[s[i] - 'a'][i][i] = 1;
      }

      for(int len = 2; len <= n; ++len){
        for(int i = 0; i <= n - len; ++i){
          int j = i + len - 1;
          for(int x = 0; x < 4; ++x){
            char c = 'a' + x;
            if(s[i] == c && s[i] == s[j]){
              dp[x][i][j] = (2LL + dp[0][i+1][j-1] + dp[1][i+1][j-1] + dp[2][i+1][j-1] +
               dp[3][i+1][j-1]) % MOD;
            }else if(s[i] == c && s[j] != c){
              dp[x][i][j] = dp[x][i][j-1];
              dp[x][i][j] %= MOD;
            }else if(s[i] != c && s[j] == c){
              dp[x][i][j] = dp[x][i+1][j];
              dp[x][i][j] %= MOD;
            }else if(s[i] != c && s[j] != c){
              dp[x][i][j] = dp[x][i+1][j-1];
              dp[x][i][j] %= MOD;
            }
          }
        }
      }

      int res = 0;
      for(int i = 0; i < 4; ++i){
        res += dp[i][0][n-1];
        res %= MOD;
      }
      return res;
    }
};

int main(){

  return 0;
}