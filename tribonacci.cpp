#include<iostream>
#include<vector>

using namespace std;

    int tribonacci(int n)
    {
        if(n <= 1) return n;
        if(n == 2) return 1;
        int q = 0, p = 1, s = 1, r = 0;
        for(int i = 3; i <= n; ++i)
        {
            r = q + p + s;
            q = p;
            p = s; 
            s = r; 
        } 

        return r;
    }

int main()
{
    cout << tribonacci(25) << endl;
}