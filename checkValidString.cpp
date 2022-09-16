#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

    bool checkValidString(string s) {
        stack<int> stk;
        stack<int> index; //记录 * 的位置
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                stk.push(i);
            }else if(s[i] == '*'){
                index.push(i);
            }else{
                if(!stk.empty())    
                    stk.pop();
                else if (index.size() != 0)
                    index.pop();
                else
                    return false;
            }
        }

        while(!stk.empty() && ! index.empty())
        {
            if(stk.top() < index.top()){
                stk.pop();
                index.pop();
            }else{
                return false;
            }
        }
        cout << stk.size() << endl;
        return stk.empty();
    }

int main(){
    return 0;
}