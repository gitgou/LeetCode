#include<iostream>
#include<vector>
using namespace std;

    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size();
        int mid = low + (high - low)/ 2;
        while(low < high){
            mid = low + (high - low)/ 2;
            if(nums[mid] < nums[high])
            {
                high = mid;
            }else{
                low = mid + 1;
            }
        }

        return nums[low]; 
    }