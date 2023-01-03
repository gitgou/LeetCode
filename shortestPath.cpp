#include<iostream>
#include<vector>
#include<queue>

using namespace std;
constexpr int move_x[4] = {-1, 0, 0, 1};
constexpr int move_y[4] = {0, 1, -1, 0};
class Solution {
public:

    void dfs(vector<vector<int>>& grid, int x, int y){
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                int index_x = x + move_x[i], index_y = y + move_y[j];
                if(index_x < 0 || index_x >= _m || index_y < 0 || index_y >= _n)
                    continue;

                if(grid[index_x][index_y] == 1){
                    continue;
                }
                _vecCost[index_x][index_y] = min(_vecCost[x][y] + 1, _vecCost[index_x][index_y]);
                cout << "_vecCost " << index_x << ", y, " << index_y << ": " << _vecCost[index_x][index_y] << endl;
            }
        }
    }

    //dfs & dynamic plan
    int shortestPath(vector<vector<int>>& grid, int k) {
        //cout << "max" << INT16_MAX << endl;
        _m = grid.size(), _n = grid[0].size();
        _vecCost.resize(_m, vector<int>(_n, INT16_MAX));
        _vecCost[0][0] = 1;
        for(int i = 0; i < _m; ++i){
            for(int j = 0; j < _n; ++j){
                if(grid[i][j] == 1){
                    break;
                }    
                dfs(grid, i, j);
            }
        }

        return _vecCost[_m - 1][_n - 1] >= INT16_MAX ? -1 : _vecCost[_m - 1][_n - 1];
    }

private:
    size_t _m,_n;
    queue<pair<int,int>> _hash;
    vector<vector<int>> _vecCost;
};