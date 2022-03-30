#include<iostream>
#include<vector>
//344. 反转字符串
using namespace std;

    void reverseString(vector<char>& s)
    {
        for(int i = 0; i < s.size() / 2; ++i)
        {
            char tmp = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - i - 1] = tmp;
        }
        
    }

int main()
{
    vector<char> s{'h', 'e', 'l', 'l', 'o'};
    reverseString(s);
    for(auto& c : s)
    {
        cout << c ;
    }
    cout << endl;
    return 0;
}