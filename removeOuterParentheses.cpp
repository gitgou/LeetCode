#include<iostream>
#include<stack>
#include<string>

using namespace std;
string removeOuterParentheses(string s) 
{
    string result;
    stack<char> st;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '(' )
        {
            if(!st.empty())
            {
                result.push_back(s[i]);
            }
            st.push(s[i]);
            
        }
        else
        {
            st.pop();
            if(!st.empty())
            {
                result.push_back(s[i]);
            }
        } 
    }

    return result;
}

int main()
{
    cout << removeOuterParentheses("()(()(()))") << endl;
    return 0;
}