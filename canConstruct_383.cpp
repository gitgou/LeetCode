#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

    bool canConstruct(string ransomNote, string magazine) {
      unordered_map<char, int> hash;
      for (size_t i = 0; i < magazine.size(); i++)
      {
        hash[magazine[i]] += 1;
      }
    
      for(size_t i = 0; i < ransomNote.size(); ++i){
        hash[ransomNote[i]] -= 1;
        if(hash[ransomNote[i]] < 0){
          return false;
        }
      }
      return true;
    }

int main(){
  return 0;
}