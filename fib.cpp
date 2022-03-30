#include<iostream>
#include<vector>

using namespace std;
    int fib(int n)
    {
        if(n <= 1) return n;
        int q = 0, p = 1, r = 0;
        for(int i = 2; i <= n; ++i)
        {
            r = q + p;
            q = p;
            p = r;
        }
        return r;
        //边界条件
        /*
        if(n <= 1)  return n;
        static vector<int> dp(n + 1, -1);
        if(dp[n] != -1)
        {
            return dp[n];
        }

        if(dp[n - 1] == -1)
        {
            dp[n - 1] = fib(n - 1);
        }
        if(dp[n - 2] == -1)
        {
            dp[n - 2] = fib(n - 2);
        }
        
        for(auto & i : dp)
        {
            cout << i << " ";
        }
        cout << endl;
        return dp[n - 1] + dp[n - 2];
        */
    }

int main()
{
    cout << fib(8) << endl; 
    return 0;
}