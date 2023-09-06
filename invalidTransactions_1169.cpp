#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:

    void dealString(const string& str, vector<string>& tmp){
      int start = 0;
      for(int i = 0; i < 3; ++i){
        int end = str.find(',', start);
        tmp.push_back(str.substr(start, end - start));
        start = end + 1;
      }
      tmp.push_back(str.substr(start, str.size() - start));
      //tmp.push_back(str);
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
      vector<string> res;
      unordered_multimap<string, vector<string>> hash;
      unordered_set<int> repeated_res;
      for(int i = 0; i < transactions.size(); ++i){
        vector<string> tmp;
        dealString(transactions[i], tmp);        
        if(atoi(tmp[2].c_str()) > 1000){
          repeated_res.insert(i);
          res.push_back(transactions[i]);
        }

        auto range = hash.equal_range(tmp[0]); //hash.find(tmp[0]);
        for(auto ite = range.first; ite != range.second; ++ite){
          if(ite->second[3] != tmp[3] && abs(atoi(ite->second[1].c_str()) - atoi(tmp[1].c_str())) <= 60){
            if(repeated_res.find(i) == repeated_res.end()){
              res.push_back(transactions[i]);
              repeated_res.insert(i);
            }
            int tmp_index = atoi(ite->second[4].c_str());
            cout << "tmp_index " << tmp_index << "ite: " << ite->second[3] << endl;
            if(repeated_res.find(tmp_index) == repeated_res.end()){
              res.push_back(transactions[tmp_index]);
              repeated_res.insert(tmp_index);
            }
            
            
          }
        }

        tmp.push_back(to_string(i));
        hash.insert(make_pair(tmp[0], tmp));
      }

      return res;
    }

};