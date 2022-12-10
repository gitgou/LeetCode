#include<iostream>
#include<vector>
using namespace std;
    //o(n) Floyd 判圈算法 -- 快慢指针; 0 -> 环起点 == 相遇位置到环起点
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }