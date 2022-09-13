#include<iostream>
#include<string>
#include<vector>

using namespace std;
    //回溯法， 递归
    void backtrack(vector<string>&results, string cur, int open, int close, int n){
        if(cur.size() == 2 * n){
            results.push_back(cur);
        }

        if(open < n){
            cur.push_back('(');
            backtrack(results, cur, open + 1, close, n);
            cur.pop_back();
        }

        if(close < open){
            cur.push_back(')');
            backtrack(results, cur, open, close + 1, n);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> results;
        string cur;
        backtrack(results, cur, 0, 0, n);
        return results;
    }
int main()
{
    return 0;
}