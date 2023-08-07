#include<vector>
#include<iostream>
using namespace std;

    bool isSubsequence(string s, string t) {
      if(s.size() == 0)
        return true;
      
      if(t.size() == 0)
        return false;

      int index = 0;
      for(int i = 0; i < t.size(); ++i){
        if(s[index] == t[i])
          index++;
        if(index == s.size())
          return true;
      }
      return false;
    }