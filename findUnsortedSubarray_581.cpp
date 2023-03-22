#include<vector>
#include<iostream>

using namespace std;


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int maxn = INT_MIN, right = -1; //记录最大值 maxn 如果nums[i] < maxn ,right 右移
        int minn = INT_MAX, left = -1;
        int length = nums.size();
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > maxn){
                maxn = nums[i];
            }else{
                right = i; //nums[i] < 左边记录最大值,需要反转
            }

            if(nums[length - i - 1] < minn){
                minn = nums[length - i - 1];
            }else{
                left = length - i - 1;
            }

            return right == -1 ? 0 : right - left + 1;
        }
    }
};