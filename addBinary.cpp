#include<iostream>
#include<string>

using namespace std;
string addBinary(string a, string b)
{
    string result;
    int carry = 0;
    int index_a = a.size() - 1, index_b = b.size() - 1;
    while(index_a >= 0 && index_b >= 0)
    {
        int i = a[index_a] - 48;
        int j = b[index_b] - 48;
        char c = (i + j + carry) % 2 + 48;
        carry = (i + j + carry) / 2;
        result.push_back(c);
        --index_a; --index_b;
    }
    cout << "reverse s1 : " << result << endl;
    //单层遍历
    while(index_a >= 0)
    {
        int i = a[index_a] - 48;
        char c = (i + carry) % 2 + 48;
        carry = (i + carry) / 2;
        result.push_back(c);
        --index_a;
    }

    while(index_b >= 0)
    {
        int i = b[index_b] - 48;
        char c = (i + carry) % 2 + 48;
        carry = (i + carry) / 2;
        result.push_back(c);
        --index_b;
    }

    if(carry == 1)
    {
        result.push_back((char)carry + 48);
    }
    
    cout << "result : " << result << endl;

    string s;
    for(int i = result.size() - 1; i >= 0; --i)
    {
        s.push_back(result[i]);
    }

    return s;
}

int main()
{
    string a = "101";
    string b = "101";
    cout << addBinary(a, b) << endl;
    return 0;
}