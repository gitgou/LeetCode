#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> L(a.size(), 1);
        for(int i = 1; i < a.size(); ++i){
            L[i] = L[i-1] * a[i-1];
        }

        vector<int> ans(a.size(), 1);
        int R = 1;
        for(int i = a.size() - 1; i >= 0; --i){
            ans[i] = L[i] * R;
            R *= a[i];
        }

        return ans;
    }
};