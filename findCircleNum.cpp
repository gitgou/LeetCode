#include<iostream>
#include<vector>
using namespace std;

    int dfs(vector<vector<int>>& isConnected, vector<int>& visited, int start){
        visited[start] = 1;
        for(int i = 0; i < isConnected.size(); ++i){
            if(isConnected[start][i] == 1 && visited[i] == 0){
                dfs(isConnected, visited, i);
            }
        }
        return 0;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
        int iCities = isConnected.size();
        vector<int> visited(isConnected.size(), 0);
        for(int i = 0; i < iCities; ++i){
            if(visited[i] != 1){
                dfs(isConnected, visited, i);
                ++res;
            }
        }

        return res;
    }