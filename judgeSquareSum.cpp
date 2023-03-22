#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 2, j = 1;
        int max = sqrt(c);
        for(int i = 2; i < max + 1; ++i){
            for(int j = 1; j < i; ++j){
                if(pow(i, 2) + pow(j, 2) == c){
                    return true;
                }
            }
        }
        return false;
    }
};