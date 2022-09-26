#include<iostream>
#include<vector>
using namespace std;

    bool canWinNim(int n) {
        // n % (m + 1) != 0 时， 先手总是会赢的
        n = n % 4;
        return n == 0 ? false : true;
    }

int main(){
    return 0;
}