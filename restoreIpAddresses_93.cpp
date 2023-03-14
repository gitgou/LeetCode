#include<iostream>
#include<vector>

using namespace std;

//回溯法
/*
    目标：找到合适的 IP 地址，
    约束：满足4段，每段 0 ~ 255
    分支：选择每一个数字放到每一段中 
*/
class Solution {
public:
    //回溯法 深度递归 -- 转化为树形结构
    void dfs(const string & s, int segID, int segStart)
    {
        if(segID == SEG_LENGTH){
            //已经有4段，且s已经遍历完
            if(segStart == s.size()){
                string ipAddr;
                for(int i = 0; i < SEG_LENGTH; ++i){
                    ipAddr.append(segment[i]);
                    if(i != SEG_LENGTH - 1){
                        ipAddr.push_back('.');
                    }
                }
                ans.push_back(ipAddr);
            }
            return;
        }
        
        if(segStart == s.size()){
            return;
        }
        //首字母如果是 0 ，就提前回溯
        if(s[segStart] == '0'){
            segment[segID] = "0";
            dfs(s, segID + 1, segStart + 1);
            return;
        }

        //分支，选择s所有元素
        int seg = 0;
        for(int segEnd = segStart; segEnd < s.size(); ++segEnd){
            seg = seg * 10 + s[segEnd] - '0';
            if(seg >= 0 && seg <= 0xFF){
                segment[segID] = to_string(seg);
                dfs(s, segID + 1, segEnd + 1);
            } else{
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        segment.resize(SEG_LENGTH);
        dfs(s, 0, 0);
        return ans;
    }
private:
    vector<string> segment;
    vector<string> ans;
    static constexpr  int SEG_LENGTH = 4;
};