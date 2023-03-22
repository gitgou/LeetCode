#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> num(N, 0);
  for(int i = 0; i < N; ++i){
    cin >> num[i];
  }
  //贪心算法
  int maxNum = 0;
  unordered_map<int, int> hash;
  for(int i = 0, j = 0; i < N; ++i){
    if(hash.count(num[i]) != 0){
        hash[num[i]] = i;
    }else{
        int tmp = hash[num[i]];
        hash[num[i]] = i;
        while(hash.size() > K){
            hash.erase(num[j++]);
        }
    }
    maxNum = std::max(maxNum, i - j + 1);
  }

  cout << maxNum << endl;
  return 0;
}