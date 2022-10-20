#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int length = 0; 
        int i = 0;
        //cout << chars.size() << endl;
        while(i < chars.size()){
            int j = i ;
            int count = 0;
            chars[length++] = chars[i]; 
            for(;j < chars.size(); ++j){
                cout << "i: " << i << ", j: " << j << endl;
                if(chars[i] == chars[j]){
                    count++;
                }else 
                    break;
            }
            cout << count << endl;
            if(count > 1){
                string s = to_string(count);
                for(auto &k : s)
                    chars[length++] = k; 
            }          
        
            i = j;
        } 
        return length;

    }

};

