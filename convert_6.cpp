#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows > s.size()){
            return s;
        }
        vector<string> vecStr(numRows);
        int row = 0, t = 2 * numRows - 2;
        for(int i = 0; i < s.size(); ++i){
            vecStr[row].push_back(s[i]);
            int x = (i-1)/2 + 1;
            
            if(i % t < numRows - 1)
                row++;
            else{
                row--;
            }
            
        }
        string res;
        for(int i = 0; i < numRows; ++i){
            cout << vecStr[i] << endl;
            res += vecStr[i];
        }

        return res;
    }
};