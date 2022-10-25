#include<vector>
#include<iostream>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums)
    {
        _vec.resize(nums.size(), 0);
        _vec[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            _vec[i] = _vec[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return left > 0 ? _vec[right] - _vec[left - 1] : _vec[right];
    }

    vector<int> _vec;
};