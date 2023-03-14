#include<iostream>
#include<vector>
using namespace std;
    vector<int> getRow(int rowIndex) {
        
        vector<int> curr, pre;
        pre.push_back(1);
        for(int i = 0; i <= rowIndex; ++i){
            curr.resize(i + 1);
            curr[0] = 1;
            curr[i] = 1;//第 i 行
            for(int j = 1; j < i; ++j){
                curr[j] = pre[j - 1] + pre[j];
            }

            pre = curr;
        }
        return curr;
    }
