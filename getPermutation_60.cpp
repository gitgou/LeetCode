#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

  bool dfs(string& tmp){
    
    if(tmp.size() == n){
      //cout << "tmp " << tmp << endl;
      if(k == 1){
        res = tmp;
        return true;
      }else{
        k--;
      }
    }

    for(int i = 0; i < n; ++i){
      if(visited[i])
        continue;
      tmp.push_back('1' + i);
      visited[i] = true;
      if(dfs(tmp))
        return true;
      tmp.pop_back();
      visited[i] = false;
    }

    return false;
  }

  int jiecheng(int x){
    if(x == 0 || x == 1){
      return 1;
    }

    return x * jiecheng(x-1);
  }

  string getPermutation(int n, int k) {
    // 从 i 开始的排序数有 m 个, k/m 即为只需遍历从 k/m 开始的排序
    int m = jiecheng(n-1);
    int start = k/m;
    this->n = n;
    this->k = k % (m+1);
    visited.resize(n, false);
    visited[start] = true;
    string tmp;
    tmp.push_back('1' + start);
    dfs(tmp);
    return res;
  }

private:
  vector<bool> visited;
  int n;
  int k;
  string res;
};

int main(){

  return 0;
}