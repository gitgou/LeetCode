#include<vector>
using namespace std;
class Solution {
public:
    void dfs(vector<int>& nums){
        if(permute.size() == nums.size())
        {
            ans.push_back(permute);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false)
                continue;
            if(!visited[i]){
                permute.push_back(nums[i]);
                visited[i] = true;
                dfs(nums);
                visited[i] = false;
                permute.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        visited.resize(nums.size(), false);
        dfs(nums);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> permute;
    vector<bool> visited;
};