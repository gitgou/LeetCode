#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

    int lastStoneWeight(vector<int>& stones) {
        multiset<int, std::greater<int>> setStones;
        for(int stone : stones){
            setStones.insert(stone);
        }
        cout << *setStones.begin() << endl;
        while (setStones.size() > 1)
        {
            int x = *setStones.begin();
            setStones.erase(setStones.begin());
            int y = * (setStones.begin());
            setStones.erase(setStones.begin());
            if(x != y){
                setStones.insert(x - y);
            }
        }
        return setStones.size() != 0 ? *setStones.begin() : 0;
    }