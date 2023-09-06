#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAlt = 0;
        int preSum = 0;
        for(int i = 0; i < gain.size(); ++i){
            preSum += gain[i];
            maxAlt = max(maxAlt, preSum);
        }

        return maxAlt;
    }
};