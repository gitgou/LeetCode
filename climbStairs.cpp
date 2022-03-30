#include<iostream>

using namespace std;

    int climbStairs(int n) 
    {
        if(n <= 2)  return n;
        int q = 1, p = 2, r = 0;
        for(int i = 3; i <= n; ++i)
        {
            r = q + p;
            q = p;
            p = r;
        }

        return r;
    }

int main()
{
    cout << climbStairs(5) << endl;
    return 0;
}