#include<vector>
#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> dfs(int start, int end){
        if(start > end){
            return {nullptr};
        }
        vector<TreeNode*> allTree;
        for(int i = start; i <= end; ++i){
            vector<TreeNode*> leftTree = dfs(start, i - 1);
            vector<TreeNode*> rigthTree = dfs(i+1, end);
            for(auto left : leftTree){
                for(auto right : rigthTree){
                    TreeNode * currNode = new TreeNode(i);
                    currNode->left = left;
                    currNode->right = right;
                    allTree.emplace_back(currNode);
                }
            }
        }
        return allTree;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return {nullptr};
    
        return dfs(1, n);
    }
};