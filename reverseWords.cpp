#include<iostream>
#include<string>

using namespace std;

    string reverseWords(string s) 
    {
        int pos = 0;
        int n = s.find(' ', pos);
        while(n != std::string::npos)
        {
            cout << "n: " << pos << endl;;  
            int length = n - pos;
            for(int i = pos, j = n - 1; i < pos + (length ) / 2; ++ i, --j)
            {
                std::swap(s[i], s[j]);
            }
            pos = n + 1;
            //find 返回的是下标 position
            n = s.find(' ', pos);
        }

        for(int i = pos, j = s.length() - 1; i < pos + (s.length() - pos) / 2; ++i, --j)
        {
            std::swap(s[i], s[j]);
        }

        return s;
    }

int main()
{
    string s = "Let's take LeetCode contest";
    cout << reverseWords(s) << endl; 
    return 0;
}