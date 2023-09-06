#include<vector>
#include<iostream>

using namespace std;

    int mincostTickets(vector<int>& days, vector<int>& costs) {
      // days 递增
      int n = days.size();
      if(n == 0)
        return 0;
      // dp[i] 表示 前 i 个 day 最少花费
      vector<int> dp(n + 1, INT_MAX / 2);
      dp[0] = costs[0];
      for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
          int day = days[j];
          
          if(i - day >= 30)
        }
      }
    }
int main(){

  return 0;
}