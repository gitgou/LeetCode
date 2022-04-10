#include<vector>
#include<iostream>

using namespace std;

    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        //就地哈希
        for(auto& num : nums){
            int iIndex = abs(num);
            if(nums[iIndex - 1] < 0)
                result.push_back(iIndex);
            else
                nums[iIndex - 1] = - nums[iIndex - 1];
        }

        return result;
    }

int main()
{
    vector<int> vec{4,3,2,7,8,2,3,1};
    vector<int> result =  findDuplicates(vec);
    for(auto& i : result)
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}