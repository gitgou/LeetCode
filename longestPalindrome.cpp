#include<iostream>
#include<vector>

using namespace std;

string longestPalindrome(string s) 
{
    //动态规划，转化为小问题，最优子结构
    // db[i][j] = s[i] == s[j] && db[i - 1][j - 1]
    size_t lenth = s.size();
    vector<vector<bool> > dp(lenth, vector<bool>(lenth));
    for(int i = 0; i < lenth; ++i)
        dp[i][i] = true;


    //控制左右两端距离, 必须先从距离短的开始遍历
   for(int L = 1; L < lenth; ++L)
   {
       //左端点
        for(int i = 0; i < lenth; ++ i)
        {
            int j = i + L; //右端点
            if(j >= lenth)
            {
                break;
            }

            if(s[i] != s[j])
            {
                dp[i][j] = false;
            } 
            else
            {
                if(j - i < 3)
                {
                    dp[i][j] = true;
                }
                else //动态规划等式
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }
   }

    size_t left = 0, right = 0;
    size_t longest = 0;
   for(int j = 0; j < lenth; ++j)
   {
       for(int i = 0; i <= j; ++i)
       {
           if(dp[i][j] == true)
           {
               if(j - i > longest)
               {
                   left = i;
                   right = j;
                   longest = j - i;
               }
           }
       }
   } 

    return s.substr(left, longest + 1);
    
}

int main()
{
    string s = "baabcbbaabbaa";
    cout << "result: " << longestPalindrome(s) << endl;
    return 0;
}