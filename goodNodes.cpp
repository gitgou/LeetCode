#include<iostream>
#include<vector>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

    void goodNodes(TreeNode* root, int& sum, int curMax)
    {
        if(! root)
            return;
        if(root->val >= curMax)
        {
            ++sum;
            curMax = root->val;
        }

        goodNodes(root->left, sum, curMax);
        goodNodes(root->right, sum, curMax);
    }

    int goodNodes(TreeNode* root) {
        int sum = 0;
        goodNodes(root, sum, INT32_MIN);
        return sum;
    }