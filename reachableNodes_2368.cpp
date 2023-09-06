#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:

    void dfs(int start){
      if(start >= n)
        return;
      //cout << "start " << start << endl;
      //cout << map[start].size() << endl;
      for(int i = 0; i < map[start].size(); ++i){
        int node = map[start][i];
        //cout << "node " << node << " " << start << endl;
        if(visited[node])
          continue;
      
        if(restrited_set.count(node))
          continue;
        visited[node] = true;
        ++res;
        dfs(node);
      }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
      visited.resize(n, false);
      //map.resize(n, vector<bool>(n, 0));
      map.resize(n);
      for(auto node : restricted){
        restrited_set.insert(node);
      }
      for(int i = 0; i < edges.size(); ++i){
        map[edges[i][0]].push_back(edges[i][1]);
        map[edges[i][1]].push_back(edges[i][0]);
      }
      this->n = n;
      this->res = 1;
      visited[0] = true;
      dfs(0);

      return res;
    }
  
private:
  vector<bool> visited;
  vector<vector<int>> map;
  unordered_set<int> restrited_set;
  int n;
  int res;
};

int main(){

  return 0;
}