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
    void dfs(TreeNode* root, string& res, string str){
        str.append(to_string(root->val));
        if(!root->left && !root->right){
            reverse(str.begin(), str.end());
            if(res.size() == 0)
                res = str;
            else{
                res = str < res ? str : res;
            }
            return;
        }

        if(root->left)
            dfs(root->left, res, str);
        if(root->right)
            dfs(root->right, res, str);

    }

    string smallestFromLeaf(TreeNode* root) {
        string res;
        if(!root)
            return res;
        dfs(root, res, string());
        return res;
    }
};