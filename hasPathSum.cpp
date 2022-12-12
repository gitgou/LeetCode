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
    bool preOrder(TreeNode* root, int targetSum, int sum){
        if(!root)
            return false;
        if(root->left == nullptr && root->right == nullptr)
        {
            if(sum + root->val == targetSum)
                return true;
            else 
                return false;
        }
        
        return preOrder(root->left, targetSum, sum + root->val) || preOrder(root->right, targetSum, sum + root->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        return preOrder(root, targetSum, 0);
    }
};