#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
struct compare{
    bool operator()(const string& lsh, const string& rsh)
    {   
        return (lsh + rsh > rsh + lsh ? true : false);
        /*
        if (lsh == rsh)
            return true;
        
        int lDigit =0,  rDigit = 0;
        int tmp = lsh; 
        while(tmp != 0)
        {
            tmp /= 10;    
            ++lDigit;
        }
        tmp = rsh;
        while(tmp != 0)
        {
            tmp /= 10;
            ++ rDigit;
        }

        while(lDigit != 0 && rDigit != 0)
        {

            int ml = lsh % (10 * (--lDigit == 0 ? 1 : lDigit));
            lsh %= (10 * (lDigit == 0 ? 1 : lDigit));
            int mr = rsh % (10 * (--rDigit == 0 ? 1 : rDigit));
            rsh %= (10 * (lDigit == 0 ? 1 : lDigit));
            cout << ml << ", " << mr << endl;
            if(ml > mr){
                return false;
            }else if(ml < mr){
                return true;
            }
        }

        return lDigit == 0 ? true : false; */
    } 
};
    string minNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return "";
        vector<string> vecStr;
        string s;
        for(auto  ref : nums){
            vecStr.push_back(to_string(ref));
        }
        sort(vecStr.begin(), vecStr.end(), compare());

        int iIndex = 0;
        while(s[iIndex] == '0')
        {
            ++iIndex;
        }

        return s.substr(iIndex);
    }

int main()
{
    return 0;
}