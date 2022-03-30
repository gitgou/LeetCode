#include<vector>
#include<iostream>

using namespace std;

    //selectFirst 用来判断是否选择第一个元素，如果是，那么最后一个不选
    int calcurate(vector<int>& slices, bool selectFirst)
    {
        int size = slices.size();
        int choose = (size + 1) / 3; //从 3n 个中选择 n 个；
        vector< vector<int> > dp(size + 1, vector<int>(choose + 1, 0));

        for(int i = selectFirst ? 1 : 2; i < (selectFirst ? size : size + 1); ++i)
        {
            for(int j = 1; j <= i && j <= choose; ++j)
            {
                //因为对于不合规的数据中，实际答案用不上，所以无所谓了。
                dp[i][j] = max(dp[i - 1][j], (i - 2 >= 0 ? dp[i - 2][j - 1] : 0) + slices[i - 1]);
                cout << "dp[i][j]: " << dp[i][j] << ", i " << i << ", j " << j << endl;

            }
        }

        cout << "dp[size][choose]: " << dp[size - 1][choose] << endl;
        return selectFirst ? dp[size - 1][choose] : dp[size][choose];
    }

    int maxSizeSlices(vector<int>& slices) 
    {
        //vector<int> slices_1(slices.begin(), slices.end() - 1);
        //vector<int> slices_2(slices.begin() + 1, slices.end());
        return max(calcurate(slices, true), calcurate(slices, false));
    }

int main()
{
    vector<int> slices{1, 2, 3, 4, 5, 6};
    cout << maxSizeSlices(slices) << endl;
    return 0;
}
