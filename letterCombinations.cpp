#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:

    void dfs(const string& digits, int digit_index, int internal_index){
        if(letterCom.size() == digits.size()){
            ans.push_back(letterCom);
            return;
        }
        if(internal_index >= letter[digits[digit_index] - '2'].size())
            return;
        /*
        letterCom.push_back(letter[digits[digit_index]][internal_index]);
        if(digit_index == digits.size() - 1){
            dfs(digits, 0, internal_index + 1);
        }else{
            dfs(digits, digit_index + 1, internal_index);
        }*/
        for(int i = digit_index; i < digits.size(); ++i){
            for(int j = internal_index; j < letter[digits[i] - '2'].size(); ++j){
                letterCom.push_back(letter[digits[i] - '2'][j]);
                if(digit_index == digits.size() - 1){
                    dfs(digits, i, j);
                }
            }
        }
        
    }

    vector<string> letterCombinations(string digits) {
        dfs(digits, 0, 0);
        return ans;
    }

private:
    vector<string> ans;
    string letterCom;
    static constexpr string letter[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs",
           "tuv","wxyz" };

};