#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
   
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1; //一边往递增向走，一边往递减向走
        while(x < m && y >= 0){
            if(matrix[x][y] == target){
                return true;
            }else if(matrix[x][y] < target){
                y--;
            }else{
                x++;
            }
        }
        return false;
    }

};
