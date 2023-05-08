#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> NumHash;
        //vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            if(NumHash.count(target - num)){
                return vector<int> {NumHash[target-num], i};
            }else{
                NumHash.emplace(pair<int, int>(num, i));
            }
        }
        return vector<int>();
    }
};
