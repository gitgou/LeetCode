#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //桶思想
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> vec(26);
        for(auto ch : tasks) ++vec[ch - 'A'];

        sort(vec.begin(), vec.end(), std::less());
        int cnt = 0;
        while(cnt < vec.size() && vec[cnt] == vec[0]) ++cnt;
        //桶的容量为 n + 1 桶的个数为 vec[0] 
        return max((int)tasks.size(), cnt + (n + 1) * (vec[0] - 1));
    }
};
