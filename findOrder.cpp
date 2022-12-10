#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    void dfs(int v)
    {
        _visited[v] = 1;
        for(int u : _edges[v]){
            if(_visited[u] == 0){
                dfs(u);
                if(!_valid)
                    return;
            }else if(_visited[u] == 1){
                _valid = false; //judge is cycle
                return;
            }
        }
        _visited[v] = 2;
        _result.push_back(v);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        _edges.resize(numCourses);
        _visited.resize(numCourses);
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            _edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0; i < numCourses && _valid; ++i)
        {
            if(! _visited[i])
                dfs(i);
        }
        if(!_valid)
            return vector<int>();
        
        reverse(_result.begin(), _result.end());
        return _result;
    }


private:
    vector<vector<int> > _edges;
    vector<int> _visited;
    vector<int> _result;
    bool _valid = true;
};