#include<iostream>
#include<string>

using namespace std;

    int titleToNumber(string columnTitle) {
        long multiple = 1;
        int res = 0;
        for(int i = columnTitle.size() - 1; i >= 0; --i){
            int data = columnTitle[i] - 'A' + 1;
            res += multiple * data;
            multiple *= 26;
        }

        return res;
    }

int main(){
    return 0;
}