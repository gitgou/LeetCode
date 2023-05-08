#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0;
        for(int i = 1, j = 0; i < arr.size();){
            while(i < arr.size() && arr[i] < arr[i - 1]){
                ++i;
            }
            if(i == arr.size())
                return 0;
            if(arr[i] == arr[i - 1] || i == j + 1){
                j = i;
                i++;
                continue;
            }
            //下行
            while (i < arr.size() && arr[i] > arr[i - 1])
            {
                i ++;
            }
            
            res = std::max(res, i - j + 1);
            j = i - 1;
        }
        return res;
    }
};