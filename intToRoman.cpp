#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

class Solution {
public:
    string intToRoman(int num) {
      string res;
      map<int, string> _digit = {{1, "I"},{4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"},
       {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
      for(auto ite = _digit.begin(); ite != _digit.end(); ++ite){
        int x = num / ite->first;
        num = num % ite->first;
        if(x){
          while(x--)
            res += ite->second;
        }
      }   
      return res;
    }

};