#include<iostream>
#include<vector>
using namespace std;
    //动态规划~
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int row = matrix.size(), col = matrix[0].size();
        int maxSquare = 0;

    }