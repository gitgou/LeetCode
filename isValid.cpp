#include<iostream>
#include<string>
#include<stack>

using namespace std;

    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stk.push(s[i]);
            }
            else if(stk.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']'))
            {
                return false;
            }
            else if((s[i] == ')' && stk.top() == '(') 
            || (s[i] == ']' && stk.top() == '[') 
            || (s[i] == '}' && stk.top() == '{'))
            {
                stk.pop();
            }
            else
            {
                return false;
            }
        }

        if(stk.empty())
        {
            return true;
        }
        
        return false;
    }

int main()
{
    cout << isValid("}") << endl;
    return 0;
}