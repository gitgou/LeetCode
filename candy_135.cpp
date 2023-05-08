
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> leftCandy(n, 0);
        leftCandy[0] = 1;
        int res = 0;
        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i-1]){
                leftCandy[i] = leftCandy[i-1] + 1;
            }else{
              leftCandy[i] = 1;
            }
        }

        int right = 1;
        res += max(leftCandy[n-1], 1);
        for(int i = n - 2; i >= 0; --i){
            right = ratings[i] > ratings[i+1] ? right + 1 : 1;
            res += max(leftCandy[i], right);
        }
        return res;
    }
};