#include<iostream>
#include<string>
#include<stack>
using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        stk.push("/");
        int start = 1, split = 0;
        while((split = path.find('/', start)) != std::string::npos || start < path.size()){
            cout << "split " << split << endl; 
            if(split == start){
                start++;
                continue;
            }
            size_t length = split == std::string::npos ? path.size() - start : split - start;
            string subStr = path.substr(start, length);
            cout << "subStr " << subStr << " start " << start << " " << split << endl;
            if(subStr == ".."){
                if(stk.size() > 1)
                    stk.pop();
            }else if(subStr == "."){

            }else if (subStr.size() > 0){
                subStr += '/';
                stk.push(subStr);
            }
            start = split == std::string::npos ? path.size() : split + 1;
        }

        
        stack<string> tmp;
        while(!stk.empty()){
            tmp.push(stk.top());
            stk.pop();
        }
        string res;
        while (!tmp.empty())
        {
            res += tmp.top();
            tmp.pop();
        }
        if(res.size() > 1)
            res.pop_back();
        cout << res << endl;
        return res;
    }
};