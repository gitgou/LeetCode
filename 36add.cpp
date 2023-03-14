#include<vector>
#include<string>
#include<iostream>
using namespace std;
string add(const string & lsh, const string & rsh)
{
    string res;
    int carry = 0, i = lsh.size() - 1, j = rsh.size() - 1;
    for(; i >= 0 && j >= 0; --i, --j){
        int l = 0, r = 0; 
        if(lsh[i] >= 'a' && lsh[i] <= 'z'){
            l = lsh[i] - 'a' + 10; 
        }else{
            l = lsh[i] - '0';
        }

        if(rsh[j] >= 'a' && rsh[j] <= 'z'){
            r = rsh[j] - 'a' + 10; 
        }else{
            r = rsh[j] - '0';
        }
    
        int sum = l + r + carry;
        carry = sum / 36;
        char c = (sum % 36) <= 9 ? (sum % 36) + '0' : (sum % 36) - 10 + 'a';
        res.push_back(c);
    }

    while (i >= 0)
    {
        int sum = lsh[i] + carry;
        char c;
        if(sum == '9' + 1){
            carry = 0;
            c = 'a';
        }else if (sum == 'z' + 1){
            carry = 1;
            c = '0';
        }else{
            carry = 0;
            c = sum;
        }

        res.push_back(c);
        cout << "res: " << res << "c: " << c << endl;
        --i; 
    }
    while (j >= 0)
    {
        int sum = rsh[j] + carry;
        char c;
        if(sum >= '0' && sum <= '9'){
            carry = 0;
            c = sum;
        }else if(sum == '9' + 1){
            carry = 0;
            c = 'a';
        }else if (sum == 'z' + 1){
            carry = 1;
            c = '0';
        }

        res.push_back(c);
        ++j; 
    }
    if(carry == 1)
        res.push_back('1');    
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    cout << add("abbbb", "1") << endl;
}