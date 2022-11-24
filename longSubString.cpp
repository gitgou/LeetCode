#include<iostream>
#include<string>
#include<vector>
using namespace std;

int longestSubstring(string s, int k) 
{

    //遍历26个字母区间
    int length = s.size();
    int ret = 0;
    for(int i = 1; i <= 26; ++i)
    {

        vector<int> vecLetter(26, 0);
        int l = 0, r = 0;
        int totalKind = 0, less = 0;
        while(r < length)
        {
            vecLetter[s[r] - 'a']++;

            // 查看右指针前向移动时的变化
            if(vecLetter[s[r] - 'a'] == 1)
            {
                ++totalKind;
                ++less;
            }
            
            if(vecLetter[s[r] - 'a'] == k)
            {
                --less;
            }

            //左指针右移
            while (totalKind > i)
            {
                vecLetter[s[l] - 'a']--;
                
                if(vecLetter[s[l] - 'a'] == k - 1)
                {
                    ++less;
                } 

                if(vecLetter[s[l] - 'a'] == 0)
                {
                    --totalKind;
                    --less;
                }

                ++l;
            }

            //判断是否为满足条件的子串
            if(less == 0)
            {
                ret = std::max(ret, r - l + 1);
            }

            ++r;             
        }
    }

    return ret;
}

int main()
{
    int ret = longestSubstring("bbaaacbd", 3);
    cout << "ret : " << ret << endl;
    return 0;
}