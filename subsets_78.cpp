#include<vector>
#include<iostream>
using namespace std;
class Solution {
private:
    vector<int> subset;
    vector<vector<int>> ans;
public:

    void dfs(vector<int>& nums, int size, int last)
    {
        //cout << "sub.size: " << subset.size() << ", ans:" << ans.size() << ", size" << size << endl;
        //cout << last << endl;
        if(subset.size() == size){
            ans.emplace_back(subset);
            return;
        }
        if(last >= nums.size())
            return;

        for(int i = last; i < nums.size(); ++i){
            cout << "i " << i << ", " << nums[i] << endl;
            subset.push_back(nums[i]);
            dfs(nums, size, i + 1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //ans.push_back(vector<int>());
        for(int size = 0; size <= nums.size(); ++size)
        {
            //cout << "size: " << size << endl;
            dfs(nums, size, 0);
        }

        return ans;
    }
};