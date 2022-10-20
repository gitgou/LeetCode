#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
using namespace std;

    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int>  res(nums.size(), 0);
        res[0] = 1;
        //左边乘积 
        for(int i = 1; i < nums.size(); ++i)
        {
            res[i] =  nums[i - 1] * res[i - 1];   //全部取左边的数 
        }
        int R = 1; //右边数
        for(int i = nums.size() - 1; i >= 0; --i)
        {
            res[i] = res[i] * R; //left * right 
            R = R * nums[i];
        }

        return res;
    }