#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

    bool back(vector<vector<char>>& board, string word, vector<vector<bool>>& hash, int row, int col){
        if(word.size() == 0)
            return true;
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return false;
        if(hash[row][col] == true)
            return false;
        if(board[row][col] != word[0])
            return false;

        hash[row][col] = 1;
        word = word.substr(1);
        if(back(board, word, hash, row - 1, col) == false && 
                back(board, word, hash, row + 1, col) &&
                back(board, word, hash, row , col - 1) &&
                back(board, word, hash, row , col + 1)){
                    hash[row][col] = false;
                    return false;
                }
                
        return true;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool> > hash(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(back(board, word, hash, i, j)){
                    return true;
                }
            }
        }
        return false;

    }