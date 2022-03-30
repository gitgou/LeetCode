#include<iostream>
#include<vector>

using namespace std;
    
    // 二分法， 如何找条件，丢弃一半的范围
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        //int right = high;
        int mid = low + (high - low)/2;

        while(low < high)
        {
            cout << "mid: " << mid << ", low: " << low << ", high: " << high<< endl;
            mid = low + (high - low)/2;
            if(nums[mid] > nums[high]){
                low = mid + 1;
            }else{
                high = mid;
            }  
        }

        return nums[low];
    }

int main()
{
    vector<int> vec{2, 1};
    cout << findMin(vec) << endl;
    return 0;
}