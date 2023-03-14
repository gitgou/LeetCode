#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    vector<string> ans;

public:
    void dfs(string & s, int last){
        while(last < s.size() && s[last] >= '0' && s[last] <= '9')
            ++last;
        if(last == s.size()){
            ans.push_back(s);
            return;
        }

        s[last] ^= 32;
        dfs(s, last + 1);  
        s[last] ^= 32;
        dfs(s, last + 1);
        
    }
    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return ans;
    }
};