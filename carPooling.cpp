#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    // 因为 from 和 to 都在 [0, 1000]。
    // 所以数组开 1005 就够了，多开五个空间防止越界
    static const int MAXN = 1005;

    int diff[MAXN];


    bool carPooling(vector<vector<int>>& trips, int capacity) {
        for (auto trip : trips) {
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        }

        for (int i = 0; i < MAXN; i++) {
            if (i != 0) diff[i] += diff[i - 1];
            if (diff[i] > capacity) return false;
        }

        return true;
    }
};

