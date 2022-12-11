#include<iostream>
#include<queue> 
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

    int height(TreeNode* root){
        if(root == nullptr)
            return 0;
        
        return std::max(height(root->left), height(root->right)) + 1;
    }

    int height_v2(TreeNode* root){
        //层次遍历求树高
        if(!root)
            return 0;
        queue<TreeNode*> Q;
        int level = 0;
        TreeNode* rear = root, * last = root;
        Q.push(root);
        while(!Q.empty())
        {
            TreeNode* node = Q.front();
            Q.pop();
            if(node->left){
                last = node->left;
                Q.push(node->left);
            }
            if(node->right){
                last = node->right;
                Q.push(node->right);
            }

            if(node == rear){
                rear = last;
                ++level;
            }
        }
        return level;
    }

    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }

    return (std::abs(height(root->left) - height(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};