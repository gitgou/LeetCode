#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

    bool isIsomorphic(string s, string t) {
      if(s.size() != t.size())
        return false;
      unordered_map<char, char> hash1, hash2;
      for(int i = 0; i < s.size(); ++i){
        if(hash1.count(s[i]) == 0 && hash2.count(t[i]) == 0){
          hash1[s[i]] = t[i];
          hash2[t[i]] = s[i];
        }else if(hash1.count(s[i]) == 0 && hash2.count(t[i]) != 0){
          return false;
        }else if( hash1.count(s[i]) != 0 && hash1[s[i]] != t[i]){
          return false;
        }
      }

      return true;
    }