#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
    
bool isStraight(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());

    int zeros = 0;
    int start = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] == 0)
        {
            ++zeros;
        }
        else
        {
            start = i;
            break;
        }
    }

    int gap = 0;
    for(int i = start + 1; i < nums.size(); ++i)
    {
        if(nums[i] == nums[i - 1])
        {
            return false;
        }
        gap += nums[i] - nums[i - 1] - 1;
    }
    cout << "zeors: " << zeros << " gap: " << gap << " start: " << start << endl; 
    if(gap > zeros)
    {
        return false;
    }
    return true;
}

int main()
{
    vector<int > vec{0, 2, 4, 6, 5};
    cout << isStraight(vec) << endl;
    return 0;
}