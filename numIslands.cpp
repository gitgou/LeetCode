#include<iostream>
#include<vector>

using namespace std;

    void dfs(vector<vector<char> >& grid, int col/* 列 */, int row /* 行 */)
    {
        int size_row = grid.size();
        int size_col = grid[0].size();
        grid[row][col] = '0';
        //图的递归
        if(row - 1 >= 0 && grid[row - 1][col] == '1') dfs(grid, col, row - 1);
        if(row + 1 < size_row && grid[row + 1][col] == '1') dfs(grid, col, row + 1);
        if(col - 1 >= 0 && grid[row][col - 1] == '1') dfs(grid, col - 1, row);
        if(col + 1 < size_col && grid[row][col + 1] == '1') dfs(grid, col + 1, row);
    }

    int numIslands(vector<vector<char> >& grid) {
        if(grid.size() == 0)
        {
            return 0;
        }

        int num_lands = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    ++ num_lands;
                    dfs(grid, j, i);
                }
            }
        }

        return num_lands;
    }

int main()
{
    return 0;
}