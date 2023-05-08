#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(nullptr));
        return quickSelect(nums, 0, nums.size()-1, nums.size() - k);
    }
    
    int quickSelect(vector<int>& nums, int l, int r, int index){
        int q = randomPartion(nums, l, r);
        if(q == index){
            return nums[q];
        }
        return q < index ? quickSelect(nums, q+1, r, index) : quickSelect(nums, l, q-1, index);
    }

    int randomPartion(vector<int>& nums, int l, int r){
        int i = random() % (r-l+1) + l;
        std::swap(nums[i], nums[l]);
        return partional(nums, l, r);
    }

    int partional(vector<int>& nums, int l, int r){
        int privot = nums[l];
        while (l < r)
        {
            while(r >= l && nums[r] >= privot) r--;
            nums[l] = nums[r];
            while(l <= r && nums[l] <= privot) l++;
            nums[r] = nums[l];
        }
        nums[l] = privot;
        return l;
    }
};