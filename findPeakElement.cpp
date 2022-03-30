#include<iostream>
#include<vector>

using namespace std;

//上坡下坡...
int findPeakElement(vector<int>& nums) 
{
    int left = 0, right = nums.size() - 1;
    while(left < right) //不能挂等号,可能会导致越界，size == 1时
    {
        int mid = left + (right - left) / 2; //避免越界
        if(nums[mid] > nums[mid + 1])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

int main()
{
    vector<int> vec{1,2,1,3,5,6,4};
    cout << findPeakElement(vec) << endl;
    return 0;
}
