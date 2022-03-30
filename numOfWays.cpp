 #include<iostream>
#include<vector>

using namespace std;
    //填的是网格， 就是一个数学递推公式
    int numOfWays(int n) 
    {
        const int mod = 1000000007;
        int aba = 6, abc = 6;
        for(int i = 1; i < n; ++i)
        {
            int newabc = (2LL * abc + 2LL * aba) % mod;
            int newaba = (2LL * abc + 3LL * aba) % mod;
            abc = newabc;
            aba = newaba;
        }
        cout << "abc " << abc << " aba: " << aba << endl; 
        return (abc + aba) % mod;
    }

int main()
{
    cout << numOfWays(2) << endl;
    return 0;
}

