#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;
    //前缀和
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mapPre;
        mapPre[0] = 1;
        int count = 0;
        int pre = 0;
        for(auto& num : nums){
            pre += num;
            if(mapPre.find(pre - k ) != mapPre.end() ){
                count += mapPre[pre - k];
            }
            mapPre[pre]++;
        }

        return count;
    }