#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        string res;
        int m = num1.size(), n = num2.size();
        vector<int> arr(m + n); 
        for(int index1 = m -1; index1 >= 0 ; --index1)
        {
            for(int index2 = n - 1; index2 >= 0; --index2){
                int tmp1 = num1[index1] - '0', tmp2 = num2[index2] - '0';
                arr[index1 + index2 + 1] += tmp1 * tmp2;
            }
        }

        for(int i = m + n - 1; i > 0; --i){
            int tmp = arr[i];
            arr[i] = tmp % 10;
            arr[i-1] = arr[i-1] + tmp / 10;
        }
        int start = arr[0] == 0 ? 1 : 0;
        for(int i = start; i < m + n; ++i){
            res.push_back(arr[i] + '0');
        }
        return res; 
    }
};