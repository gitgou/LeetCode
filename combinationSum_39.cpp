#include<vector>
using namespace std;
class Solution {
public:
    void dfs(vector<int>& candicates, int target, int idx){
        if(idx == candicates.size())
            return; 

        if(target == 0){
            ans.push_back(combinate);
            return ;
        }
        //深度直接 idx + 1
        dfs(candicates, target, idx + 1);
        
        if(target - candicates[idx] >= 0){
            combinate.push_back(candicates[idx]);
            dfs(candicates, target - candicates[idx], idx);
            combinate.pop_back();
        }
        return ;
    }
 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);  

        return ans;  
    }

private:
    vector<vector<int>> ans;
    vector<int> combinate;
};