#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
      if(s.size() == 0)
        return true;

      int left = 0, right = s.size() - 1;
      while (left < right)
      {
        if(s[left] >= 'A' && s[left] <= 'Z')
          s[left] ^= 32;
        if(s[right] >= 'A' && s[right] <= 'Z')
          s[right] ^= 32;
        cout << s[left] << " " << s[right] << endl;
        if((s[left] < 'a' || s[left] > 'z') && (s[left] < '0' || s[left] > '9')){
          left++;
          continue;
        }
        if((s[right] < 'a' || s[right] > 'z') && (s[right] < '0' || s[right] > '9') ){
          right--;
          continue;
        }

        if (s[left] == s[right]){
          left++;
          right--;
        }else{
          return false;
        }
      }
      return true;
    }
};