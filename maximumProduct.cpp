#include<iostream>
#include<vector>

using namespace std;
    int maximumProduct(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        return max(nums[0] * nums[1] * nums[2], nums[nums.size() - 1] * nums[nums.size() -2] * nums[nums.size() - 3]);
    }

int main()
{
    vector<int> vec{1, 2, 3};
    cout << maximumProduct(vec) << endl;
    return 0;
}