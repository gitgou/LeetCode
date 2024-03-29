#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(citations.size() - mid == citations[mid]){
                return citations.size() - mid;
            }else if(citations.size() - mid > citations[mid]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return left;
    }
};