#include<vector>
#include<queue>
#include<iostream>

using namespace std;

//广度优先搜索和深度优先搜索算法必须熟悉。 又忘了...
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int> > updateMatrix(vector<vector<int> >& mat) 
{
    vector<vector<int> > result(mat.size(), vector<int>(mat[0].size(), 0));
    //标记数组，表示已经遍历过
    vector<vector<bool> > viewed(mat.size(), vector<bool>(mat[0].size(), false));
    queue<pair<int, int> > q; //pair存放点位置信息
    for(int i = 0; i < mat.size(); ++i)
    {
        for(int j = 0; j < mat.size(); ++j)
        {
            if(mat[i][j] == 0)
            {
                result[i][j] = 0;
                viewed[i][j] = true;
                q.emplace(i, j); //since c++ 11 传入构造参数，右值引用
            }
        }
    }

    //开始遍历
    while (!q.empty())
    {
        pair<int, int> location = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int row = location.first + dirs[i][0];
            int col = location.second + dirs[i][1];
            if(row >= 0 && row < mat.size() && col >= 0 && col < mat[0].size() && ! viewed[row][col])
            {
                result[row][col] = result[location.first][location.second] + 1;
                viewed[row][col] = true;
                q.emplace(row, col);
            }
        }
    }
    
    return result;
}

int main()
{
    vector<vector<int> > vec{ {0,1,0}, {1, 1, 1}, {0, 1, 0} };
    vector<vector<int> > result = updateMatrix(vec);

    for(int i = 0; i < result.size(); ++i)
    {
        for(int j = 0; j < result[0].size(); ++j)
        {
            cout << result[i][j] << " " ;
        }
        cout << endl;
    }   

    return 0;
}