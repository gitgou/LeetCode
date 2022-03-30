#include<iostream>
#include<vector>

using namespace std;

    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int mid = low + (high - low)/2;

        while(low < high)
        {
            cout << "mid: " << mid << ", low: " << low << ", high: " << high<< endl;
            mid = low + (high - low)/2;
            if(nums[mid] > nums[high]){
                low = mid + 1;
            }else if(nums[mid] < nums[high]){
                high = mid;
            }else{
                --high;
            }  
        }

        return nums[low];
    }

int main()
{
    vector<int> vec{2, 2, 2, 0, 1};
    cout << findMin(vec) << endl;
    return 0;
}