#include<iostream>
#include<vector>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        nums = vector<vector<int>> (m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0 && j == 0){
                    nums[i][j] = matrix[i][j];
                }else if(i == 0){
                    nums[i][j] = nums[i][j - 1] + matrix[i][j];
                }else if(j == 0){
                    nums[i][j] = nums[i - 1][j] + matrix[i][j];
                }else{
                    nums[i][j] = nums[i - 1][j] + nums[i][j - 1] - nums[i - 1][j - 1] + matrix[i][j]; 
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        //cout << "row2 " << row2 << " col2 " << col2 << " row1 " << row1 << " col1 " << col1 << endl; 
        if(col1 == 0 && row1 == 0)
            return nums[row2][col2];
        else if(col1 == 0)
            return nums[row2][col2] - nums[row1 - 1][col2];
        else if(row1 == 0)
            return nums[row2][col2] - nums[row2][col1 - 1];
        else 
            return nums[row2][col2] - nums[row1 - 1][col2] - nums[row2][col1 - 1] + nums[row1 - 1][col1 - 1];
    }

private:
    vector<vector<int>> nums;
};
