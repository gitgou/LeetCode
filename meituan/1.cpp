#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
  int n,m;
  cin >>n >> m;
  vector<int> edges(n, 0);
  for(int i = 0; i < n; ++i){
    cin >> edges[i];
  }
  //cout << "n " << n << " " << m << endl;
  std::sort(edges.begin(), edges.end());
  for(int i = 0; i < m; ++i){
    long long q = 0, res = 0, sum = 0;
    cin >> q;
    for(int j = 0; j < edges.size(); ++j){
      sum += pow(edges[j], 2);
      if(sum > q){
        cout << j << " ";
        break;
      }
    }
  }  
  cout << endl;
  
  return 0;
}