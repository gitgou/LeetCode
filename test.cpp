#include<iostream>

using namespace std;
int test()
{
  cout << "123" << endl;
  int c= 1;
}
int main(){
  int a = 1;
  cout << "test" << endl;
  test();
  a = 2;
  return 0;
}