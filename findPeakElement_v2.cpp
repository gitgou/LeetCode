#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //寻找最大值、二分迭代法
    //pairs first compare pair.first, then pair.second
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        auto get = [&] (int i) -> pair<int, int> {
            if(i == -1 || i == n)
                return {0, 0};
            else 
                return {1, nums[i]};
        };
        int index = rand() % n;
        while (!(get(index - 1) < get(index) && get(index) > get(index + 1))){ 
            cout << "get(index): " << get(index).second << endl;
            if(get(index + 1) > get(index))
                index += 1;
            else    
                index -= 1;
        }
        return index;
    }
};