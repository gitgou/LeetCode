#include<vector>
#include<iostream>
using namespace std;
class Solution {
private:
    vector<int> subset;
    vector<vector<int>> ans;
    vector<bool> visited;
public:
    void dfs(vector<int>& nums, int size, int last)
    {

        if(subset.size() == size){
            ans.emplace_back(subset);
            return;
        }
        if(last >= nums.size())
            return;

        for(int i = last; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false)
                continue;
            //cout << "i " << i << ", " << nums[i] << endl;
            visited[i] = true;
            subset.push_back(nums[i]);
            dfs(nums, size, i + 1);
            visited[i] = false;
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        visited.resize(nums.size(), false);
        for(int size = 0; size <= nums.size(); ++size)
        {
            //cout << "size: " << size << endl;
            dfs(nums, size, 0);
        }

        return ans;
    }
};