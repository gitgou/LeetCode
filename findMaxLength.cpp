#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash;
        hash[0] = -1;
        int count = 0, maxLength;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 1){
                count++;
            }else{
                count--;
            }
            if(hash.count(count)){
                maxLength = std::max(maxLength, i - hash[count]);
            }else{
                hash[count] = i;
            }
        }

        return maxLength;
    }
};