#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

void splitString(const string& s, unordered_map<string, string>& res){
  int start = 0, split = 0;
  while((split = s.find('=', start)) != std::string::npos){
    string key = s.substr(start, split - start);
    start = split + 1;
    int split2 = s.find(';', start);
    string value = s.substr(start, split2 - start);
    start = split2 + 1;
    res[key] = value;
    cout << "key:" << key << "; value:" << value << endl;
  }
}

int main(){
  string s;
  cin >> s;
  unordered_map<string, string> hash;
  splitString(s, hash);
  int q = 0;
  cin >> q;
  for(int i = 0; i < q; ++i){
    string key;
    cin >> key;
    if(hash.count(key)){
        cout << hash[key] << endl;
    }else{
        cout << "EMPTY" << endl;
    }
  }
  return 0;
}