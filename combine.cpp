#include<iostream>
#include<vector>

using namespace std;
//回溯法 important
class Solution {
public:
    void back(int n, int k, int index){
        if(_tmp.size() == k){
            _res.push_back(_tmp);
            return;
        }
        //经典回溯法模型
        for(int i = index; i <= n; ++ i)
        {
            _tmp.push_back(i);
            back(n, k, i + 1);
            _tmp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        back(n, k, 1);
        return _res;
    }

private:
    vector<int> _tmp;
    vector<vector<int>> _res;
};