#include<vector>
#include<iostream>
#include<string>
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
    void dfs(TreeNode* root, vector<string>& res, string str){
        str.append(to_string(root->val));
        if(!root->left && !root->right){
            res.emplace_back(str);
            return;
        }else{
            str += "->";
        }
        if(root->left)
            dfs(root->left, res, str);
        if(root->right)
            dfs(root->right, res, str);

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root)
            return res;
        dfs(root, res, string());
        return res;
    }
};