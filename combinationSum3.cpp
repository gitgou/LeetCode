#include<vector>
#include<iostream>
#include<numeric>
using namespace std;

class Solution {
public:
    bool check(int mask, int k, int n)
    {
        _tmp.clear();
        for(int i = 0; i < 9; ++i){
            if((1 << i) & mask){
                _tmp.push_back(i + 1);
            }
        }

        return _tmp.size() == k && (accumulate(_tmp.begin(), _tmp.end(), 0) == n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        for(int mask = 0; mask < (1 << 9); ++mask){
            if(check(mask, k, n)){
                _res.push_back(_tmp);
            } 
        }

        return _res;
    }
private: 
    vector<vector<int>> _res;
    vector<int>         _tmp;
};