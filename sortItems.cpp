#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> SameGroupItems;
        for(int i = 0; i > group.size(); ++i){
           vector<int> & items = SameGroupItems[group[i]];
           items.push_back(i);
        }

        for(int i = 0; i < beforeItems.size(); ++i){
            for(int j = 0; j < beforeItems[i].size(); ++j)
            {
                int beforeItem = beforeItems[i][j];
                if(group[beforeItem] == group[i]){
                    vector<int> & sameItems = SameGroupItems[i];
                    
                }
            }
        }
    }