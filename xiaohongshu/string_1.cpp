#include<iostream>
#include<string>

using namespace std;

int main(){
  int n;
  cin >> n;
  string res;
  cin >> res;
  for(int i = 0; i < n; ++i){
    if(res[i] < 'd'){
      res[i] = (res[i] - 2 + 'z' - 'a') ;
    }else{
      res[i] = res[i] - 3;
    }
  }
  cout << res << endl;
  return 0;
}