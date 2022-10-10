#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

    int nextGreaterElement(int n) {
        string s = to_string(n);
        //char min = s.size() - 1;
        for(int i = s.size() - 1; i > 0; --i){
            if(s[i - 1] < s[i]){
                int iMin = i;
                while(iMin < s.size() && s[iMin] > s[i - 1]) ++iMin;
                swap(s[i - 1], s[iMin - 1]);
                //再往小的数值规划
                sort(s.begin() + i, s.end(), std::less());
                break;
            }
        }

        int res = atoi(s.c_str());
        if(res <= n){
            return -1;
        }else{
            return res;
        }
    }