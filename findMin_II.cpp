#include<iostream>
#include<vector>
using namespace std;

    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int mid = low + (high - low) / 2;
        while(low < high){
            mid = low + (high - low) / 2;
            if(nums[mid] < nums[high])
            {
                high = mid;
            }else if(nums[mid] > nums[high]){
                low = mid + 1;
            }else if(nums[mid] == nums[high]){
                high -= 1;
            }
        }
        return nums[low];
    }