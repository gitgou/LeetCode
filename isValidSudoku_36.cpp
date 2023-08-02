#include<iostream>
#include<vector>
using namespace std;
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<vector<bool>>> subBoxes(3, vector<vector<bool>>(3, vector<bool>(9, false)));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j] - '1';
                if(rows[i][num] == true)
                    return false;
                else 
                    rows[i][num] = true;

                if(cols[j][num] == true)
                    return false;
                else
                    cols[j][num] = true;

                if(subBoxes[i / 3][j / 3][num] == true)
                    return false;
                else
                    subBoxes[i / 3][j / 3][num] = true;
            }
        }
        return true;
    }