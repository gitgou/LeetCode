#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int diff =std::abs((int)first.size() - (int)second.size()); 
        if(diff >= 2){
            return false;
        }
        if(diff == 0){
            int gap = 0;
            for(int i = 0; i < first.size(); ++i){
                if(first[i] != second[i]){
                    gap++;
                }
            }
            if(gap > 1){
                return false;
            }else{
                return true;
            }
        }else{
            int i = 0, j = 0;
            bool flag = false;
            for(;i < first.size() && j < second.size(); ){
                //判断是不是只相差 1
                if(first[i] != second[j]){
                    if(flag)
                        return false;
                    if(first.size() > second.size()){
                        ++j;
                    }else{
                        ++i;
                    }
                    flag = true;
                }else{
                    ++i; ++j;
                }
                
            }

            return true;
        }
    }
};