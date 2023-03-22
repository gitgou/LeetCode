#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int i = 0, j = height.size() - 1;
        while(i < j){
            int area = std::min(height[i], height[j]) * (j - i);
            maxArea = std::max(maxArea, area);
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxArea;
    }
};

int main(){
    return 0;
}