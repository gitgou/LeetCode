#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int findNearestLand(int x, int y){
        queue<Coordinate> Q;
        Q.push(Coordinate(x,y,0));
        while (!Q.empty()){
            Coordinate coord = Q.front();
            Q.pop();
            for(int i = 0; i < 4; ++i){
                int nx = coord._x + dx[i], ny = coord._y + dy[i];
                if(nx < 0 || nx >= size || ny < 0 || ny >= size)
                    continue;

                if(_vis[nx][ny] == false){
                    Q.push({nx, ny, coord._step + 1});
                    _vis[nx][ny] = true;
                    if(_grid[nx][ny] == 1)
                    {
                        return coord._step + 1;     
                    }
                }


            }
        }
        return -1; 
    }

    int maxDistance(vector<vector<int>>& grid) {
        size = grid.size();
        int maxDistance = -1;
        _grid = grid;
        for(int i = 0; i < size; ++i){
            for(int j = 0; j < size; ++j){
                memset(_vis, false, sizeof(bool)*100*100);
                if(grid[i][j] == 0){
                    maxDistance = max(maxDistance, findNearestLand(i, j));
                }
            }
        }
        return maxDistance;
    }

private:
    struct Coordinate
    {
        Coordinate(){};
        Coordinate(int x, int y, int step)
        :_x(x)
        ,_y(y)
        ,_step(step)
        {
        }
        int _x,_y,_step;
    };
    int size;
    bool _vis[100][100];
    vector<vector<int>> _grid;
    static constexpr int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};   
};