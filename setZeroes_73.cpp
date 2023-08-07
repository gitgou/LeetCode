#include<vector>

using namespace std;

    void setZeroes(vector<vector<int>>& matrix) {
      // 空间复杂度 o(m+n): 使用 set<int> 存储 
      // 空间复杂度 o(1)
      // matrix[0][0] 标记 matrixp[0][j] 是否需置 0
      bool flag_col0 = false;
      int m = matrix.size(), n = matrix[0].size();
      //包含第一行
      for(int i = 0; i < m; ++i){
        if(!matrix[i][0])
          flag_col0 = true;
        
        for(int j = 1; j < n; ++j){
          if(!matrix[i][j]){
            matrix[i][0] = 0;
            matrix[0][j] = 0;
          }
        }
      }
      
      // 此处遍历需包含第一行，以 matrix[0][0] 为准
      for(int i = m - 1; i >= 0; --i){
        for(int j = 1; j < n; ++j){
          if(matrix[i][0] == 0 || matrix[0][j] == 0){
            matrix[i][j] = 0;
          }
        }

        if(flag_col0)
          matrix[i][0] = 0;
      }
      
    }

int main(){
  return 0;
}
