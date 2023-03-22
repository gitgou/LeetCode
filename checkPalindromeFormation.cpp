#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(const string & s, int left, int right){
        for(int i = left, j = right; i < j; ++i, --j){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }

    bool checkPalindrome(const string& a, const string& b) {
        int i = 0, j = a.size() - 1;
        while(i < j && a[i] == b[j]){
            i++;
             --j;          
        }
        if(i >= j){
            return true;
        }

        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    }
        

    bool checkPalindromeFormation(string a, string b) {
        return checkPalindrome(a,b) || checkPalindrome(b, a);
    }
};

int main(){
    return 0;
}