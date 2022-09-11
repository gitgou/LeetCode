#include <iostream>
#include <vector>
#include<algorithm>
#include<map>
using namespace std;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        multimap<int, int> Hash;
        sort(nums.begin(), nums.end());
        int  i = 0;
        while(i < nums.size())
        {
            int num = nums[i];
            size_t size = 0;
            while(i < nums.size() && nums[i] == num){
                ++size;
                ++i;
            }

            Hash.insert(make_pair(size, nums[i - 1]));
            if(Hash.size() > k){
                Hash.erase(Hash.begin());    
            }     
            
        }

        vector<int> result;
        for(auto& ref : Hash){
            result.push_back(ref.second);
        }

        return result;
    }

int main()
{
    return 0;
}