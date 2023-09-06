#include<vector>
#include<string>


using namespace std;
class Solution {
public:

  bool canInsertQ(vector<string>& tmp, int i, int j){
    for(int k = 0; k < n; ++k){
      if(tmp[k][j] == 'Q')
        return false;
      if(tmp[i][k] == 'Q'){
        return false;
      }
      int tmpi = i + k, tmpj = j + k;
      if(tmpi < n && tmpj < n && tmp[tmpi][tmpj] == 'Q'){
        return false;
      }
      
      tmpi = i - k, tmpj = j - k;
      if(tmpi >= 0 && tmpj >= 0 && tmp[tmpi][tmpj] == 'Q'){
        return false;
      }

      tmpi = i - k, tmpj = j + k;
      if(tmpi >= 0 && tmpj < n && tmp[tmpi][tmpj] == 'Q'){
        return false;
      }

      tmpi = i + k, tmpj = j - k;
      if(tmpi < n && tmpj >= 0 && tmp[tmpi][tmpj] == 'Q'){
        return false;
      }
    }
    return true;
  }

  bool isRepeated(vector<string>& tmp2){
    for(int j = 0; j < res.size(); ++j){
      bool flag = true;
      for(int i = 0; i < n; ++i){
        if(res[j][i] != tmp2[i])
            flag = false;
      }
      if(flag == true)
        return true;
    }
    return false;
  }

  void dfs(vector<string>& tmp, int size){
    // 有些情况不可能会达到 n
    if(size == n){
      if(!isRepeated(tmp))
        res.push_back(tmp);
      return;
    }

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        if(canInsertQ(tmp, i, j)){
          tmp[i][j] = 'Q';
          dfs(tmp, size+1);
          tmp[i][j] = '.';
        }
      }
    }
  }
  vector<vector<string>> solveNQueens(int n) {
    string s;
    this->n = n;
    s.reserve(n);
    for(int i = 0; i < n; ++i){
      s.push_back('.');
    }
    vector<string> tmp(n, s);
    dfs(tmp, 0);
    return res;
  }

private: 
  vector<vector<string>> res;
  // vector<vector<bool>> visited;
  int n;
};

int main(){

  return 0;
}