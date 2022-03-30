#include<string>
#include<vector>
#include<iostream>

using namespace std;
    string longestCommonPrefix(vector<string>& strs) 
    {
        string result;
        if(strs.size() == 0)
        {
            return result;
        }

        for(int index = 0; index < 200; ++index)
        {
            if(strs[0].size() > index)
            {
                char c = strs[0][index];
                for(int j = 1; j < strs.size(); ++j)
                {
                    if(c != strs[j][index])
                    {
                        return result;
                    }

                    if(j == strs.size() - 1)
                    {
                        result.push_back(c);
                    }
                }
            }
            else
            {
                return result;
            }
        }
        return result;
    }

int main()
{
    vector<string> strs{"flow","flow"};

    cout << longestCommonPrefix(strs) << endl;
    return 0;
}