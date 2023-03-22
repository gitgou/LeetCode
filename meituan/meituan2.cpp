#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Compare{
  bool operator()(const vector<int> & left, const vector<int>& right){
    if(left[0] < right[0]){
      return true;
    }else if(left[0] > right[0]){
      return false;
    }else{
      return left[1] < right[1];
    }
  }
};

int main(){
  int N,A,B;
  cin >> N >> A >> B;
  vector<vector<int>> vec(N, vector<int>(2, 0));
  //vector<vector<bool>> tag(N, vector<int>(N, false));
  for(int i = 0; i < N; ++i){
    cin >> vec[i][0] >> vec[i][1] ;
  }
  
  std::sort(vec.begin(), vec.end(), Compare());
  for(int i = 0 ; i < vec.size(); ++i)
  cout << "vec " << vec[i][0] << "," << vec[i][1] << endl;
  int maxNum = 0;
    int start = 0;
    for(int j = 0; j < N; ++j){
      if(std::abs(vec[start][0] - vec[j][0]) <= A && std::abs(vec[start][1] - vec[j][1]) <= B){
        if(j == N - 1){
          maxNum = std::max(maxNum, j - start + 1);
        }
        continue;
      }else{
        maxNum = std::max(maxNum, j - start);
        while(std::abs(vec[start][0] - vec[j][0]) > A || std::abs(vec[start][1] - vec[j][1]) > B){
          ++start;
        }
      }

  }
  cout << maxNum << endl;
  return 0;
}
