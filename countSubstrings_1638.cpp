#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int countSubstrings(string s, string t) {
      // 关键点在于找到 s[i] 不等于 t[j]时 
      //dpl[i][j] 以 s[i] s[j] 为终点的左边最长相等序列 以及 右边最长相等序列 dpr[i][j] 
      int n = s.size(), m = t.size();
      vector<vector<int>> dpl(n + 1, vector<int>(m + 1, 0)), dpr(n + 1, vector<int>(m + 1, 0));
      for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
          dpl[i+1][j+1] = s[i] == t[j] ? dpl[i-1][j-1] + 1 : 0; 
        }
      }

      for(int i = n - 1; i >= 0; --i){
        for(int j = m - 1; j >= 0; --j){
          dpr[i][j] = s[i] == t[j] ? dpr[i+1][j+1] + 1 : 0;
        }
      }

      int res = 0;
      for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
          if(s[i] != t[j]){
            res += (dpl[i][j] + 1) * (dpr[i+1][j+1] +1);
          }
        }
      }
      return res;
    }
};

int main(){

  return 0;
}