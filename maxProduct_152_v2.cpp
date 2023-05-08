#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minNum = nums[0], maxNum = nums[0], ans = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            maxNum = std::max(maxNum * nums[i], std::max(minNum*nums[i], nums[i]));
            minNum = std::min(maxNum * nums[i], std::min(minNum*nums[i], nums[i]));
            ans = std::max(maxNum, ans);
        }
        return ans;
    }
};