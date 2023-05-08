#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if(arr[mid] == target){
                return true;
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


        return false;
    }
};