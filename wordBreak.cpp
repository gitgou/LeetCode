//139. 单词拆分

#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>

using namespace std;


bool wordBreak(string s, vector<string>& wordDict)
{
    //o(1)
    unordered_map<string, bool> hash;
    for(auto& s : wordDict)
    {
        hash.insert(make_pair(s, true));
    }
    //对于内置数据类型元素的数组，必须使用()来显示指定程序执行初始化操作，否则程序不执行初始化操作;
    bool *dp = new bool[s.size() + 1]();
    dp[0] = true;
    //dp[i] 表示 0 ~ i - 1 的子字符串是否可拆分
    for(int i = 1; i <= s.size(); ++i)
    {
        //从0开始，因为
        for(int j = 0; j < i; ++j)
        {
            if(dp[j] && hash.find(s.substr(j , i - j)) != hash.end())
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[s.size()];
}

int main()
{
    string s = "applepenapple";
    vector<string> vec = {"apple", "pen"};
    cout << wordBreak(s, vec) << endl;
    //cout << s.find("dogs") << endl;
    //cout << s.substr(0,2) << endl;
    return 0;
}