#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string modifyString(string s) {
        char a = 'a';
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '?'){
                if(s.size() == 1){
                    s[i] = a;
                    break;
                }
                if(i == 0 ){
                    while(a == s[i+1])
                        a = (a - 'a' + 1)%26 + 'a';
                    s[i] = a;
                }else if(i == s.size() - 1){
                    while(a == s[i - 1])
                        a = (a - 'a' + 1)%26 + 'a';
                    s[i] = a;
                }else{
                    while(a == s[i + 1] || a == s[i - 1])
                        a = (a - 'a' + 1)%26 + 'a';
                    s[i] = a;
                }
            }
        }
        return s;
    }
};