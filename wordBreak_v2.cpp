#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> mapWord;
        for(auto & s : wordDict)
            mapWord.insert(make_pair(s, true));

        vector<bool> f(s.size(), false);
        if(mapWord.find(s.substr(0,1)) != mapWord.end())
            f[0] = true;
        else
            f[0] = false;

        for(int i = 1; i < s.size(); ++i){
            for(int j = 0; j <= i; ++j){
                string subStr = s.substr(j, i - j + 1);
                if(j == 0 && mapWord.find(subStr) != mapWord.end())
                    f[i] = true;
                else if(mapWord.find(subStr) != mapWord.end() && f[j - 1] == true)
                    f[i] = true;

            
            }
        }

        return f[s.size() - 1];
    }

int main()
{

    string s("123");
    cout << s.substr(0,2) << endl;
}