#include<vector>
#include<iostream>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;
struct  Compare
{
    bool operator()(const pair<string, int>& rsh, const pair<string, int>& lsh) const
    {
        if(rsh.second > lsh.second)
            return true;
        if(rsh.second == lsh.second)
            return rsh.first < lsh.first;

        return false;
    }
    
};


    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mapWord;
        set<pair<string, int>, Compare> setWord;
        vector<string> result;
        for(auto& s : words)
        {   
            ++mapWord[s];
        }

        for(auto& pair : mapWord)
        {
            setWord.insert(make_pair(pair.first, pair.second));
        }

        for(auto ite = setWord.begin(); ite != setWord.end() && result.size() < k; ++ite)
        {
            result.push_back(ite->first);
        }

        return result;
    }

int main()
{
    return 0;
}