#include <iostream>
#include <vector>

using namespace std;

int midSearch(vector<int>& nums, int low, int high, int target)
{
    cout << "low: " << low << "high: " << high << endl;
    if(low < 0 || high >= nums.size() || low > high)
    {
        return -1;
    }
;
    while (high >= low)
    {
        int mid = ( high + low ) / 2;
        if(nums[mid] == target)
        {
            return mid;
        }

        if(nums[mid] < target)
        {
            return midSearch(nums, mid + 1, high, target);
        }
        else
        {
            return midSearch(nums, low, mid -1, target);
        }
    
    }
    
    return -1;
}
int search(vector<int>& nums, int target)
{
    int k = 1;
    while(k < nums.size() && nums[k] > nums[0])
    {   ++k;    }

    int result = -1;

    result = midSearch(nums, 0, k - 1, target);
    cout << "result: " << result << "k " << k << endl;
    if(result != -1)
    {
        return result;
    }

    result = midSearch(nums,  k , nums.size() - 1, target);

    return result;

}


int main()
{
    vector<int> vec = {4};
    int result = search(vec, 0);

    cout << "result: " << result << endl;
    return 0;
}