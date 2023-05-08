#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // 动态规划 
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left <= right)
        {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if(leftMax < rightMax){
                res += (leftMax - height[left]);
                left++;
            }else{
                res += (rightMax - height[right]);
                right--;
            }
        }
        return res; 
    }
};