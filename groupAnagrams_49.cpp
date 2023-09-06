#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> res;
      unordered_map<string, vector<string>> hash;
      for(int i = 0; i < strs.size(); ++i){
        string tmp = strs[i];
        sort(tmp.begin(), tmp.end());
        if(hash.count(tmp)){
          hash[tmp].push_back(strs[i]);
        }else{
          hash.insert(pair<string, vector<string>>(tmp, vector<string>()));
          //hash.emplace((tmp, vector<string>()));
          hash[tmp].push_back(strs[i]);
        }
      }

      for(auto ite : hash){
        res.emplace_back(std::move(ite.second));
      }
      
      return res;
    }

int main(){

  vector<int> vec {2,1,3,4};
  sort(vec.begin(), vec.end(), std::less<int>());
  return 0;
}