#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int fast = 0, slow = 0;
        vector<string> vec;
        while(fast < s.size()){
            while (slow < s.size() && s[slow] == ' ')
            {
                ++slow;
            }
            fast = slow;
            while (fast < s.size() && s[fast] != ' ')
            {
                ++fast;
            }
            vec.push_back(s.substr(slow, fast - slow));
        }

        string res;
        for(int i = vec.size() - 1; i >= 0; --i){
            res += vec[i];
            if(i != 0){
                res += " ";
            }
        }
        return res;
    }
};