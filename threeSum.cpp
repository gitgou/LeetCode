#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
    vector<vector<int> > threeSum(vector<int>& nums)
    {
        //std::find(nums.begin(), nums.end(), 0);
        //std::find(nums, 0);
        vector<vector<int> > result;
        //不能重复也可以使用set<struct>来去重
        if(nums.size() < 3)
        {
            return result;
        }
        std::sort(nums.begin(), nums.end()); //必须先排序，避免得到重复的元祖
    
        //双指针一个前向，一个后向, 就可以做一个二分了，使得时间复杂度降为log(n)
        for(int i = 0; i < nums.size(); ++i)
        {
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int k = nums.size() - 1;
            int target = -nums[i];
        
            for(int j = i + 1; j < nums.size(); ++j)
            {
                if(j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                while (j < k && nums[j] + nums[k] > target)
                {
                    --k;
                }
                //必须放前 
                if(j == k)
                {
                    break;
                }

                if(nums[j] + nums[k] == target)
                {
                    result.push_back(vector<int>{nums[i], nums[j], nums[k]});
                }

                
            }

        }

        return result;


    }
int main()
{
    vector<int> vec{-1,0,1,2,-1,-4};
    vector<vector<int> > result = threeSum(vec);
    for(int i = 0; i < result.size(); ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}