#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        int lsum = 0, rsum = 0; //记录
        for(int right = 0, left = 0;right < nums.size(); ++right){
            rsum += 1 - nums[right];
            while(left < right && lsum < rsum - k){
                lsum += 1 - nums[left];
                left++;
            }
            res = std::max(res, right - left + 1);
        }
        return res;
    }
};