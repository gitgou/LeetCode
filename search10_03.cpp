#include<vector>
#include<iostream>

using namespace std;
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        int res = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if(arr[mid] == target){
                res = mid;
                break;
            }else if(arr[mid] > arr[left]){
                if(arr[left] <= target && target < arr[mid]){ //在前半段
                    right = mid - 1;
                }else{ //在后半段
                    left = mid + 1;
                }               
            }else if(arr[mid] < arr[left]){
                if(arr[mid] < target && arr[right] >= target){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }else{
                left++;
            }
        }
        cout << "res " << res << endl;
        while(res - 1 >= 0){
            if(arr[res] == arr[0]){
                res = 0;
                break;
            }
            if(arr[res-1] == arr[res]){
                res--;
            }else{
                break;
            }
        }

        return res;
    }
};