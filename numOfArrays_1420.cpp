#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    const int base = 1e9 + 7;
    int numOfArrays(int n, int m, int k) {
      if(m < k)
        return 0;

      // dp[i][s][j] 数组长度为 i, cost 为 s, j 为最大值的数组数
      vector<vector<vector<int>>> dp(51, vector<vector<int>>(101, vector<int>(101, 0)));

      //  初始化 i = 1, s = 1, j = i 
      for(int i = 1; i < 101; ++i){
        dp[1][1][i] = 1;
      } 

      // j >= s
      for(int i = 2; i <= n; ++i){
        for(int s = 1; s <= k; ++s){
          for(int j = s; j <= m; ++j){

            dp[i][s][j] = dp[i-1][s][j] * j % base;
            for(int index = 1; index < j; ++index){
              dp[i][s][j] += (dp[i-1][s-1][index] % base);
            }

          }
        }
      }

      int res = 0;
      for(int i = 1; i <= m; ++i){
        res += (dp[n][k][i] % base);
      }
      return res;
    }
};

int main(){
  return 0;
}