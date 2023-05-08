#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string res = s.substr(n);
        res += s.substr(0, n + 1);
        return res;
    }
};