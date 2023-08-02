#include<iostream>
#include<vector>
using namespace std;

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int leftBroad = 0, rightBroad = m - 1,
            upBroad = 1, downBroad = n - 1;
        int i = 0, j = 0;
        while (leftBroad < rightBroad || upBroad < downBroad)
        {
            while(j <= rightBroad)
                res.push_back(matrix[i][j++]);
            
            rightBroad--;
            j--, i++;

            while (i <= downBroad)
            {
                res.push_back(matrix[i++][j]);
            }
            downBroad--;
            i--, j--;
            
            while (j >= leftBroad)
            {
                res.push_back(matrix[i][j--]);
            }
            leftBroad++;
            j++, i--;

            while (i >= upBroad){
                res.push_back(matrix[i--][j]);
            }
            upBroad++;
            i++, j++;
        }
        return res;    
    }