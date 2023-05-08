#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            int mod = sum % k;
            if(mod == 0 && i != 0)
                return true;
            if(hash.count(mod)){
                if(hash[mod] != i - 1)
                    return true;
            }else{
                hash[mod] = i;
            }
            
        }
        return false;
    }

private:
    unordered_map<int, int> hash;   
};