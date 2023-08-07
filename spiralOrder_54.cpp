#include<iostream>
#include<vector>
using namespace std;

  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> res;
    int left = 0, right = n - 1, top = 0, bottom = m - 1;
    while (true)
    {
      // left to right 
      for(int col = left; col <= right; ++col){
        res.push_back(matrix[top][col]);
      }
      if(++top > bottom)  break;

      // top to bottom 
      for(int row = top; row <= bottom; ++row){
        res.push_back(matrix[row][right]);
      }
      if(--right < left) break;

      // right to left
      for(int col = right; col >= left; --col){
        res.push_back(matrix[bottom][col]);
      }
      if(--bottom < top) break;

      // bottom to top
      for(int row = bottom; row >= top; --row){
        res.push_back(matrix[row][left]);
      }
      if(++left > right)  break;
    }
     return res;    
  }

int main(){
  // vector<vector<int> > vec{{1,2,3},{4,5,6},{7,8,9}};
  vector<vector<int>> vec{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  vector<int> res = spiralOrder(vec);
  return 0;
}