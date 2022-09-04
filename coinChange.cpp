#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

    int coinChange(vector<int>& coins, int amount) {
        //sort(coins.begin(), coins.end());
        int nums = 0;
        vector<int> f(amount + 1, 10001);
        f[0] = 0;
        for(int i = 1; i <= amount; ++i)
        {
            for(int iIndex = 0; iIndex < coins.size(); ++iIndex){
                if(coins[iIndex] <= i){
                    f[i] = min(f[i], f[i - coins[iIndex]] + 1);
                }
            }
        }

        return f[amount] == 10001 ? -1 : f[amount];
    }

int main()
{
    return 0;
}