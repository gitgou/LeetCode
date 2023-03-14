#include<vector>
#include<string>
using namespace std;

class Solution {

private: 
    vector<string> ans;
    string par;
public:

    void dfs(int n, int open, int close){
        if(par.size() == 2*n){
            ans.push_back(par);
            return;
        }
        //right
        if(open < n){
            par.push_back('(');
            dfs(n, open + 1, close);
            par.pop_back();
        }

        if(close < n){
            par.push_back(')');
            dfs(n, open, close + 1);
            par.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);
    }
};