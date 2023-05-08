#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool isPartition(const string& s){
        for(int i = 0, j = s.size() - 1; i < j; i++,j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }

    void dfs(const string& s, int start, vector<string>& vecStr){
        if(start == s.size()){
            _res.push_back(vecStr);
        }

        for(int i = start+1; i <= s.size(); ++i){
                const string& subStr = s.substr(start, i -  start);
                if(isPartition(subStr)){
                    vecStr.push_back(subStr);
                    dfs(s, i, vecStr);
                    vecStr.pop_back();
                }
            }
        }
    
    vector<vector<string>> partition(string s) {
        _res.clear();
        vector<string> vecStr;
        dfs(s, 0, vecStr);
    }
private:
    vector<vector<string>> _res;
};