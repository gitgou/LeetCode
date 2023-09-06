#include<string>

using namespace std;

class Solution {
public:
    int minSwap(string & s1, string& s2, int start){
      int total = 0;
      for(int i = start; i < s1.size(); ++i){
        if(s1[i] != s2[i])
          total++;
      }

      return (total + 1)/ 2;
    }
    void dfs(string& s1, string& s2, int start, int cost){
      if(cost > res)
        return;
      while(start < length && s1[start] == s2[start])
        start++;

      if(start == length){
        res = min(res, cost);
        return;
      }

    for(int j = start + 1; j < length; ++j){
      if(s1[start] == s2[j]){
        swap(s2[start], s2[j]);
        dfs(s1, s2, start + 1, cost + 1);
        swap(s2[start], s2[j]);
      }
    }
  }
    int kSimilarity(string s1, string s2) {
      // TODO 已经有序的，直接排除
      length = s1.size();
      res = length + 1;
      dfs(s1, s2, 0, 0);
      return res;
    }

private: 
  int length;
  int res;
};

int main(){
  return 0;
}