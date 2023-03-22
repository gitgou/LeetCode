#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0; 
        int i = 0, j = 0;
        while(i < nums.size() && nums[i] == nums[j]){
            ++i;
        } 
            
        nums[k++] = nums[0];
        if(i - j  >= 2){
            nums[k++] = nums[0];
        }

        j = i;
        for(; i < nums.size(); ++i){
            
            while(i < nums.size() && nums[i] == nums[j]){
                ++i;
            }
            if(i < nums.size()){
                nums[k++] = nums[i];
                if(i - j >= 2){
                    nums[k++] = nums[i];
                }
            }
            j = i;  
            //cout << "j " << j << endl;  
        }

        return k;
    }
};