#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size() <= k)
            return arr;

        int fast = 0;

        vector<int> res(k, 0);
        while(fast < arr.size() && arr[fast] < x){
            ++fast;
        }
        int left = fast, right = fast, i = 0;
        while(res.size() < k){
            if(left < 0){
                res[i++] = arr[right];
                continue;
            }else if(right > arr.size()){
                res[i++] = arr[left];
                continue;
            }

            if(abs(arr[left] - x) <= abs(arr[right] - x)){
                res[i++] = arr[left];
            }else{
                res[i++] = arr[right];
            }
        }
        return res;
    }
};

int main(){
    return 0;
}