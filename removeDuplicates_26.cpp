#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0; 
        nums[k++] = nums[0];
        for(int i = 1, j = 0; i < nums.size(); ++i){
            
            while(i < nums.size() && nums[i] == nums[j]){
                ++i;
            }
            if(i < nums.size())
                nums[k++] = nums[i];
            j = i;  
            //cout << "j " << j << endl;  
        }

        return k;
    }
};