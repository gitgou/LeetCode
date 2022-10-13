#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

    int romanToInt(string s) {
        map<char, int> mapNum{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int res = 0, iIndex = 0;
        while (iIndex < s.size())
        {
            if(s[iIndex] == 'I' && (iIndex + 1 < s.size()) && (s[iIndex + 1] == 'V' || s[iIndex + 1] == 'X')){
                res += mapNum[s[iIndex + 1]] - mapNum[s[iIndex]];
                iIndex +=2;
            }else if(s[iIndex] == 'X' && (iIndex + 1 < s.size()) && (s[iIndex + 1] == 'L' || s[iIndex + 1] == 'C')){
                res += mapNum[s[iIndex + 1]] - mapNum[s[iIndex]];
                iIndex +=2;
            }else if(s[iIndex] == 'C' && (iIndex + 1 < s.size()) && (s[iIndex + 1] == 'D' || s[iIndex + 1] == 'M')){
                res += mapNum[s[iIndex + 1]] - mapNum[s[iIndex]];
                iIndex +=2;
            }else{
                res += mapNum[s[iIndex]];
                ++iIndex;
            }
        }

        return res;
    }