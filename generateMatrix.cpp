#include<iostream>
#include<vector>
#include<memory>
using std::vector;
//类似于回文数, 主要在于确定边界
vector<vector<int>> generateMatrix(int n) 
{
    int l = 0, r = n - 1, u = 0, b = n - 1;
    int num = 1;
    int mat[n][n];
    memset(mat, 0, sizeof(int)*n*n);

    while (num <= n * n)
    {

        for(int i = l; i <= r; ++i) mat[u][i] = num ++;
        ++u;
        for(int i = u; i <= b; ++i) mat[i][r] = num ++;
        --r;
        for(int i = r; i >= l; --i) mat[b][i] = num ++;
        --b;
        for(int i = b; i >= u; --i) mat[i][l] = num++;
        ++l;
    }

    vector<vector<int>> result;
    for(int i = 0; i < n; ++i)
    {
        vector<int> vec;
        for(int j = 0; j < n; ++j)
        {
            vec.push_back(mat[i][j]);
            std::cout <<mat[i][j] << " ";
        }
        std::cout<< std::endl;
        result.push_back(vec);
    }

    return result;
}

int main()
{
    generateMatrix(5);
    return 0;
}