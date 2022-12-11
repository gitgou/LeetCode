#include<iostream>
#include<string>
using namespace std;

    int hammingWeight(uint32_t n) {
        int sum = 0;
        string s;
        while(n  != 0){
            s.push_back(n % 2);
            n /= 2;
        }
        for(auto c : s)
        {
            if(c == 1){
                ++sum;
            }
        }
        return sum;
    }