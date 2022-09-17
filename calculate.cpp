#include<iostream>
#include<string>
#include<stack>
using namespace std;

    int calculate(string s) {
        //全部做 1 元计算
        int result = 0;
        stack<int> symbol; //使用 1 和 -1 作为符号
        symbol.push(1);
        int i = 0, sign = 1; 
        while(i < s.size()){
            if(s[i] == ' '){
                ++i;
            }else if(s[i] == '+'){
                sign = symbol.top();
                ++i;
            }else if(s[i] == '-'){
                sign = - symbol.top();
                ++i;
            }else if(s[i] == '('){
                symbol.push(sign); // 只有遇到括号时才会把符号入栈;栈中最少有个 + 号
                ++i;
            }else if(s[i] == ')'){
                symbol.pop();
                ++i;
            }else{
                int num = 0;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
                    num = num * 10 + s[i] - '0';
                }
                result += sign * num;        
            }  

        }
        return result;  
    }

int main()
{
    return 0;
}