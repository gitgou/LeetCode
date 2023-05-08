#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size(), 0);
        stk.push(0);
        for(int i = 1; i < temperatures.size(); ++i){
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]){
                int j = stk.top();
                res[j] = i - j;
                stk.pop();
            }
            stk.push(i);
        }

        return res;
    }
};