#include <vector>
#include<algorithm>
#include <stdio.h>
using std::vector;

/*
    数组中每一个元素都可能成为比该元素大的元素的最后一个元素， 所以前面几个元素的排序组合组成 i - num 的个数即为d[i - num];
    所以 每个元素都等于i 比它小的元素num 的组合之和； d[i] += d[i -num];
*/
int combinationSum4(vector<int>& nums, int target) {
    //std::sort(nums.begin(), nums.end());   
    int * dp  = new int[target + 1]();
    dp[0] = 1;
    for(int i = 1; i <= target; ++i)
    {
        for(int num : nums)
        {
            if(i >= num)
            {
                printf("num:%d ", num);
                dp[i] += dp[i - num]; 
            }
        }

    }        
    
    printf("sizeof(long long ):%d", sizeof(long long));
    int result = dp[target];
    delete [] dp;
    return  result;
}


int main()
{
    vector<int> ver{1,2, 4};

    combinationSum4(ver, 3);
    return 0;
}