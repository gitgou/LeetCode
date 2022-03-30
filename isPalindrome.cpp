#include<iostream>
#include<string>

using namespace std;
    bool isPalindrome(int x) 
    {
        if(x < 0)
        {
            return false;
        }

        string s = std::to_string(x);
        cout << s << endl;
        for(int i = 0; i < s.size() / 2; ++i)
        {
            if(s[i] != s[s.size() - i - 1])
            {
                return false;
            }
        }

        return true;
    }

int main()
{
    cout << isPalindrome(121) << endl;
    return 0;
}