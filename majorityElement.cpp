#include<vector>
using namespace std;

class Solution {
public:
    int calElementCount(const vector<int>& nums, int element){
        int res = 0;
        for(int e : nums){
          if(e == element)
            res++;
        }
        return res;
    }
    int majorityElement(vector<int>& nums) {
      int majorityCount = nums.size() / 2;

      while (true)
      {
        int index = rand() % nums.size();
        if(calElementCount(nums, nums[index]) > majorityCount)
          return nums[index];
      }
      
    }
};