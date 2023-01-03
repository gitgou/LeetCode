#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int total = 0, ans = 0;
        for(int i = 0; i < 32; ++i){
            for(auto num : nums){
                total += ((num >> i) & 1);
            }
            //total % 3 != 0 即多余的数
            if(total % 3){
                ans |= (1 << i);
            }
        }

        return ans;
    }
};