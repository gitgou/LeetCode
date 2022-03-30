#include<iostream>
#include<vector>

using namespace std;
//全排列 回溯法
class Solution{
public:
    vector<vector<int> > permute(vector<int>& nums)
    {
        size  = nums.size();
        vector<bool> viewed(size, false);
        vector<vector<int> > result;
        backford(result, nums, viewed);

        return result;
    }

private:
    //回溯
    void backford(vector<vector<int> >& result, vector<int>& nums, vector<bool>& viewed)
    {
        //满了退出
        if(res.size() == size)
        {
            result.push_back(res);
            return;
        }

        for(int i = 0; i < size; ++i)
        {
            if(!viewed[i])
            {
                viewed[i] = true;
                res.push_back(nums[i]);
                backford(result, nums, viewed);
                viewed[i] = false;
                res.pop_back(); //退出该值表示前面位置的值为固定后的排列序列全部遍历完了
            }
        }
    }

private:
    vector<int> res;
    size_t size;
};
int main()
{
    vector<int> vec{1,2,3};
    Solution s;
    vector<vector<int> > result = s.permute(vec);

    for(int i = 0; i < result.size(); ++i)
    {
        for(int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << " ";
        }

        cout << endl;
    }
    return 0;
}