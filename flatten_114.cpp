#include<iostream>
#include<vector>

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
    TreeNode* flattenTree(TreeNode* root){
        if(!root)
            return nullptr;
        TreeNode * tmp = root->right;
        if(root->left){
            root->right = flattenTree(root->left);
        }
        TreeNode* lastRight = root->right;
        if(!lastRight){
            lastRight = root;
        }else{
            while (lastRight->right)
            {
                lastRight = lastRight->right;
            }
        }

        if(tmp){
            lastRight = flattenTree(tmp);
        }
        return root;
    }
    void flatten(TreeNode* root) {
        flattenTree(root); 
    }
};
