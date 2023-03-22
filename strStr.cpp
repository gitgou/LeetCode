#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    void GetNext(const string & needle){
        next[0] = 0;
        for(int i = 1, j = 0; i < needle.size(); ++i){
            //next: 最长的相等的真前缀与真后缀的长度(包含自身)  s[0:j−1]=s[i−j:i−1]
            //[0, j) 是一句匹配好了的，next[j]就是记录j后缀有多少与字符串 pos 0 后缀相等,如果没有 next[j] = 0;
            //子串从零开始
            while (j > 0 && needle[i] != needle[j])
            {
                j = next[j - 1];
            }
            
            if(needle[i] == needle[j]){
                j++;
            }

            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        if(needle.size() == 0 || haystack.size() == 0){
            return -1;
        }
        next.reserve(needle.size());
        GetNext(needle);
        for(int i = 0, j = 0; i < haystack.size(); ++i){
            while (j > 0 && needle[j] != haystack[i])
            {
                j = next[j - 1];
            }
            //如果 needle[j] != haystack[i], 先将 j回退, 然后 i++;
            if(needle[j] == haystack[i]){
                ++j;
            }

            if(j == needle.size()){
                return i - j + 1;
            }
        }
    }

private:
    vector<int> next;
};