#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, curr = 10e7;
        for(int i = 0; i < nums.size(); ++i){
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }


            int left = i + 1, right = nums.size() - 1; 
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target){
                    return target;
                }

                if(abs(sum - target) < curr){
                    res = sum;
                    curr = abs(sum - target);
                }

                if(sum > target){
                    int right0 = right - 1;
                    while(right0 > left && nums[right0] == nums[right]){
                        --right;
                    }
                    right = right0;
                }else{
                    int left0 = left + 1;
                    while(left0 < right && nums[left0] == nums[left]){
                        ++left;
                    }
                    left = left0;
                }
            }
        }

        return res;
    }
};

int main()
{
    vector<int> vec = {1,1,1,1};
    Solution solve;
    cout << solve.threeSumClosest(vec, 0) << endl;
}