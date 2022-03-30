#include <iostream>
#include <stack>
#include<vector>
#include<string>
using namespace std;

vector<int> maxDepthAfterSplit(string seq) 
{
    //即均分括号给两个，可采用取余的方法模2的方法均分为2, 遇到（ 将d++; 遇到 ")"将d--;
        int d = 0;
        vector<int> ans;
        for (char& c : seq)
            if (c == '(') {
                ++d;
                ans.push_back(d % 2);
            }
            else {
                ans.push_back(d % 2);
                --d;
            }
        return ans;
}

int main()
{
    return 0;
}
