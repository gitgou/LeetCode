#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
    string addStrings(string num1, string num2) 
    {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end()); 
        string result; 
        int carry = 0;
        int i = 0, j = 0; 
        for(; i < num1.size() && j < num2.size(); ++i, ++j)
        {
            int tmp = num1[i] - '0' + num2[j] - '0' + carry;
            carry = tmp / 10;
            result.append(to_string(tmp % 10));
            
        }
        //cout << result << endl;
        while(i < num1.size())
        {
            int tmp = num1[i] - '0' + carry;
            carry = tmp / 10;
            result.append(to_string(tmp % 10));
            ++i;
        }

        //cout << result << endl;
        while(j < num2.size())
        {
            int tmp = num2[j] - '0' + carry;
            carry = tmp / 10;
            result.append(to_string(tmp % 10));
            ++ j;
        }

        if(carry != 0)
        {
            result = result.append(to_string(carry));
        }

        reverse(result.begin(), result.end());

        return result;
    }

int main()
{
    cout << addStrings("11", "123") << endl;    
    return 0;
}