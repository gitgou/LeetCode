#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), std::greater());
        int h = 0;
        for(; h < citations.size(); ++h){
            if(h + 1 > citations[h]){
                break;
            }
        }
        return h;
    }
};