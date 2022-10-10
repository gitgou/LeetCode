#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

    int binarySearch(vector<int>& numbers, int target){
        int low = 0, high = numbers.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(numbers[mid] == target){
                return mid;
            }else if(numbers[mid] > target){
                high = mid - 1;
            }else if(numbers[mid] < target){
                low = mid + 1;
            }
        }

        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for(int i = 0; i < numbers.size(); ++i){
            int iIndex = -1;
            if((iIndex = binarySearch(numbers, target - numbers[i])) != -1){
                if(iIndex == i && (iIndex < numbers.size() - 1) && numbers[iIndex + 1] == numbers[iIndex])
                {
                    ++iIndex;
                }
                if(iIndex == i && (iIndex > 1) && numbers[iIndex - 1] == numbers[iIndex]){
                    --iIndex;
                }
                res.push_back(i + 1);
                res.push_back(iIndex + 1);
                return res;
            } 
        }
    }

int main(){

    return 0;
}