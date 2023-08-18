#include<vector>
#include<iostream>

using namespace std;

    int maxSubarraySumCircular(vector<int>& nums) {
      int n = nums.size(), res = nums[0], pre = nums[0], left = nums[0];
      vector<int> leftMax(n);
      leftMax[0] = nums[0];
      for(int i = 1; i < n; ++i){
        // pre 是 max nums[i:j]
        pre = max(pre + nums[i], nums[i]);
        res = max(res, pre);
        left += nums[i];
        leftMax[i] = max(leftMax[i-1], left);
      }
      int rightNum = 0;
      for(int i = n - 1; i > 0; i--){
        rightNum += nums[i];
        res = max(res, rightNum + leftMax[i-1]);
      }
      return res;
    }

int main(){
  return 0;
}