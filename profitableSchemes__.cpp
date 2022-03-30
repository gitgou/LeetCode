#include<iostream>
#include<vector>
using namespace std;

//动态规划背包问题， 不会做
class Solution
{
public:

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
    {
        vector<vector<vector<int> > > dp(group.size() + 1, vector<vector<int> >(n + 1, vector<int>(minProfit + 1, 0)));
        dp[0][0][0] = 1;
        for(int i = 1; i <= group.size() ; ++i)
        {
            int earn = profit[i - 1], members = group[i - 1];
            for(int j = 0; j <= n; ++j)
            {
                for(int k = 0; k <= minProfit; ++k)
                {
                    if(j < members)
                    {
                        //???
                        dp[i][j][k] = dp[i - 1][j][k];
                    }else
                    {   // ???
                        dp[i][j][k] = (dp[i - 1][j][k] + dp[i - 1][j - members][max(0, k - earn)]) % _MOD;

                    }
                }
            }
        }

        int sum = 0;
        for(int j = 0; j <= n; ++j)
        {
            sum += dp[group.size()][j][minProfit] % _MOD;
        }

        return sum;
    }

 private:
    const static int _MOD = 1e9 + 7;
  
};

int main()
{
    Solution s;
    vector<int> group{2, 2};
    vector<int> profit{2, 3};
    cout << s.profitableSchemes(5, 3, group, profit) << endl;
    return 0;
}