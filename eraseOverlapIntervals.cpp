#include <iostream>
#include <vector>
#include<algorithm>
using namespace std; 

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int nums = 1;
        //先排序, 贪心算法，使用的是区间右端元素排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2){ return v1[1] < v2[1];});
        int lastMax = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i][0] >= lastMax)
            {
                ++nums;
                lastMax = intervals[i][1];
            }
        }

        return intervals.size() - nums;
    }

int main()
{
    return 0;
}