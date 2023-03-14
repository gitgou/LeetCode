#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0, left = 0;        
        unordered_set<char> hash;
        for(int i = 0; i <= s.size(); ++i){
            if(hash.count(s[i]) == 1){
                hash.erase(s[left]);
                left++;
            }else{
                hash.insert(s[i]);
            }

            max = std::max(max, i - left + 1);
        }

        return max;
    }
};