#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
    int longestConsecutive(vector<int>& nums) {
      int n = nums.size();
      int res = 0;
      unordered_map<int, bool> hash;
      for(int i = 0; i < n; ++i){
        hash[nums[i]] = true;
      }

      for(auto ite = hash.begin(); ite != hash.end(); ++ite){
        if(hash.count(ite->first - 1))
          continue;

        int count = 0, start = ite->first, index = start;
        for(; hash.count(index); ++index){

        }

        res = max(res, (index - start));
      }
      return res;
    }

int main(){
  vector<int> vec{0,3,7,2,5,8,4,6,0,1};
  int res = longestConsecutive(vec);
  cout << res << endl;
  return 0;
}