#include<string>
#include<vector>
#include<iostream>

using namespace std;
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.size() == 0){
            return res;
        }

        if(strs.size() == 1){
            return strs[0];
        }

        for(int index = 0; index < strs[0].size(); ++index)
        {
           
            char c = strs[0][index];
            for(int j = 1; j < strs.size(); ++j)
            {
                if(c != strs[j][index])
                {
                    return res;
                }

                if(j == strs.size() - 1)
                {
                    res.push_back(c);
                }
            }
            
        
        }
        return res;
    }

int main(){
    return 0;
}