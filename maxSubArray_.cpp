#include<vector>
#include<iostream>
using namespace std;

//动态规划或者暴力求解法
int maxSubArray(vector<int>& nums) 
{
    int sum = 0, max = INT_MIN;
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    {
        sum += *it;
        sum = std::max(sum, *it);
        max = std::max(max, sum);
    }

    return max;
}

int main()
{
    vector<int> vec{1, 2 , -1, 5, 6};
    cout << maxSubArray(vec) << endl;
    return 0;
}