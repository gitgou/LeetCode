#include<vector>
#include<iostream>

using namespace std;
    void rotate(vector<vector<int>>& matrix) {
      // 两次反转
      int n = matrix.size();
      //水平翻转
      for(int row = 0; row < n / 2; ++row){
        std::swap(matrix[row], matrix[n - 1 - row]);
      }
      //对角线翻转
      for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
          swap(matrix[i][j], matrix[j][i]);
        }
      }
      
    }

int main(){

  return 0;
}