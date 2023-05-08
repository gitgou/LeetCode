#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, res = 10e5 + 1;
        hash[0] = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            hash[sum] = i;
            if(sum < target){
                continue;
            }

            int tmp = sum - target; //找到比 tmp 小的前缀和
            auto ite = hash.upper_bound(tmp); 
            cout << "i " << i << " " << ite->first << " "<< ite->second << endl;
            res = std::min(res, i - ite->second + 1);
        }
        return res == 10e5 + 1 ? 0 : res;
    }

private:
    map<int, int> hash;
};