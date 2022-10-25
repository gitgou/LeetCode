#include<vector>
#include<iostream>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums)
    :_vec(nums)
    {

    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i = left; i <= right; ++i){
            sum += _vec[i];
        }
        return sum;
    }

    const vector<int> & _vec;
};