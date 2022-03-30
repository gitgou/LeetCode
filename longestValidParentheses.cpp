#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

int longestValidParentheses(const string& s) 
{
    stack<int> stk;
    vector<bool> vecMark(s.length(), false); //空间换时间
    int longest = 0;
    
    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == '(')
        {
            stk.push(i);
        }
        else
        {
            if(stk.empty()) 
            {
                vecMark[i] = true;
            }else
            {
                stk.pop();
            }

        }

    }
    
    while(!stk.empty())
    {
        vecMark[stk.top()] = true;
        stk.pop();
    }

    int longs = 0;
    for(int i = 0; i < vecMark.size(); ++i)
    {
        if(vecMark[i] == false)
        {
            ++longs;
        }
        else
        {
            longs = 0;
        }
        
        if(longest < longs) {   longest = longs; }
        cout << "longs: " << longs << " longest: " << longest << endl;
    }        

    return longest;
}

int main()
{

    string str = "(()";
    cout << longestValidParentheses(str) << endl;
    return 0;
}