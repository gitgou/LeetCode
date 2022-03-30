#include<iostream>
#include<vector>

using namespace std;

    int minCostClimbingStairs(vector<int>& cost) 
    {
        int p = 0, q = 0, r = 0;
        for(int i = 0; i < cost.size(); ++i)
        {
            r = min(p , q ) + cost[i];
            p = q;
            q = r;
        }

        return min(q, p);
    }


int main()
{
    vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << minCostClimbingStairs(cost) << endl;
    return 0;
}