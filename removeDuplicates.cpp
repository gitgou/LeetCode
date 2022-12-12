#include<iostream>
#include<string>
using namespace std;

    string removeDuplicates(string s) {
        string res;
        res.push_back(s[0]);
        for(int i = 1; i < s.size(); ++i){
            if(s[i] == res.back()){
                res.erase(res.back());
            }else{
                res.push_back(s[i]);
            }
        }

        return res;
    }