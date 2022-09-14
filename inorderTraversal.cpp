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
    void inorderTraversal(TreeNode* root, vector<int>& result)
    {
        if(root->left)
            inorderTraversal(root->left, result);

        result.push_back(root->val);
        
        if(root->right)
            inorderTraversal(root->right, result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) 
            return result;
            
        inorderTraversal(root, result);

        return result;
    }


};