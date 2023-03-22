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
    int dfs(TreeNode * root){
        if(root == nullptr){
            return 0;
        }

    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == nullptr)
            return nullptr;

        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left == right){
            return root;
        }

        if(left > right){
            return lcaDeepestLeaves(root->left);
        }else{
            return lcaDeepestLeaves(root->right);
        }
    }
};