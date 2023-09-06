#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>>& grid, int i, int j, bool& isVaild){
      visited[i][j] = true;
      for(int index = 0; index < 4; ++index){
        if(i + neighbor[index][0] >= row || i + neighbor[index][0] < 0){
          isVaild = false;
          continue;
        }
        
        if(j + neighbor[index][1] >= col || j + neighbor[index][1] < 0){
          isVaild = false;
          continue;
        }

        int tmpI = i + neighbor[index][0], tmpJ = j + neighbor[index][1];
        if(grid[tmpI][tmpJ] == 0 && !visited[tmpI][tmpJ])
          bfs(grid, tmpI, tmpJ, isVaild);
      }
    }

    int closedIsland(vector<vector<int>>& grid) {
      row = grid.size(), col = grid[0].size();
      visited.resize(row, vector<bool>(col, false));
      res = 0; 
      for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
          if(!visited[i][j] && grid[i][j] == 0){
            bool isVaild = true;
            bfs(grid, i, j, isVaild);
            if(isVaild)
              res++;
          }
        }
      }

      return res;
    }

private:
  int row;
  int col;
  int res;
  vector<vector<bool>> visited;
  vector<vector<int>> neighbor = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
};

int main(){

  Solution s;
  vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
  cout << s.closedIsland(grid) << endl;
  return 0;
}