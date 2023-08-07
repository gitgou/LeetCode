#include<vector>
#include<iostream>
using namespace std;

    int arrayNesting(vector<int>& nums) {
      //利用图的特性，n个点，n条边，则必定存在环，找到最大的环
      //vector<int> map(nums.size(), false);
      int res = 0;
      for(int i = 0; i < nums.size(); ++i){
        int cnt = 0;
        while (nums[i] < nums.size())
        {
          int num = nums[i];
          nums[i] = nums.size();
          i = num;
          cnt++;
        }
        res = max(cnt, res);
      }
        return res;
    }

int main(){

  return 0;
}