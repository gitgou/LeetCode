#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isInclude(const string & first, const string& second){
        int i = 0, j = 0;
        while (i < first.size() && j < second.size())
        {
            if(first[i] == second[j]){
                ++i; ++j;
            }else{
                ++i;
            }
        }
        
        if(j == second.size() - 1)
            return true;
        
        return false;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string res;
        for(int i = 0; i < dictionary.size(); ++i){
            if(isInclude(s, dictionary[i])){
                if(dictionary[i].size() > res.size()){
                    res = dictionary[i];
                }else if(dictionary[i].size() == res.size() && dictionary[i] < res){
                    res = dictionary[i];
                }
            }
        }
        return res;
    }
};