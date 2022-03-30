#include<iostream>
#include<vector>

using namespace std;

    int rob(vector<int>& nums) 
    {
        int p = 0, q = 0, r = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            r = max(p + nums[i], q);
            p = q;
            q = r;
        }

        return r;
    }

    int robRange(vector<int>& nums, int start, int end)
    {    
        int p = 0, q = 0, r = 0;
        for(int i = start; i <= end; ++i)
        {
            r = max(p + nums[i], q);
            p = q;
            q = r;
        }

        return r;

    }
    int rob_2(vector<int>& nums)
    {
        if(nums.size() == 1)
        {
            return nums[0];
        }
        if(nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }

        return max(robRange(nums, 0, nums.size() - 2), robRange(nums, 1, nums.size() -1));
    }

int main()
{
    vector<int> nums{2, 1, 1, 2};
    cout << rob_2(nums) << endl;
    return 0;
}