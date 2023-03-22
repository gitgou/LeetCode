#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n - 3; ++i){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            //边界
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target){
                break;
            }
            //边界
            if(nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target){
                continue;
            }

            for(int j = i + 1; j < n - 2; ++j){
                if( j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }

                int left = j + 1, right = n - 1;
                while(left < right){
                    if(nums[i] + nums[j] + nums[left] + nums[right] == target){
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    
                        //指针移动
                        int left0 = left + 1;
                        while(left0 < right && nums[left] == nums[left0]){
                            left0++;
                        }
                        left = left0;
                        int right0 = right - 1;
                        while (right0 > left && nums[right] == nums[right0])
                        {
                            right0--;
                        }
                        right = right0;
                    }
                    
                    if(nums[i] + nums[j] + nums[left] + nums[right] > target){
                        int right0 = right - 1;
                        while (right0 > left && nums[right] == nums[right0])
                        {
                            right0--;
                        }
                        right = right0;
                        
                    }else{
                        left++; 
                    }

                }
            }
        }

        return res;
    }
};