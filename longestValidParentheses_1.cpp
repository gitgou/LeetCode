#include<stack>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

    int longestValidParentheses(string s) 
    {
        stack<int> st;
        vector<bool> vecMark(s.size(), true);
        //先把无法匹配的括号标记出来
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else 
            {
                if(st.empty())
                {
                    vecMark[i] = false;
                }
                else
                {
                    st.pop();
                }              
            }         
        }

        while(!st.empty())
        {
            vecMark[st.top()] = false;
            st.pop();
        }

        int longest = 0, result = 0;
        for(int i = 0; i < vecMark.size(); ++i)
        { 
            if(vecMark[i] == true)
            {
                ++longest;
            }

            result = max(result, longest);
            if(vecMark[i] == false )
            {
                longest = 0;
            }
        }
        return result;
    }

int main()
{
    string s("(()");
    cout << longestValidParentheses(s) << endl;
    return 0;
}