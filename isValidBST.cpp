#include<stack>
#include<vector>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    bool midOrder(TreeNode* root){
        int preValue = INT32_MIN;
        TreeNode * curr = root;
        std::stack<TreeNode*> stk;
        while(curr || !stk.empty()){
            if(curr){
                stk.push(curr);
                curr = curr->left;
            }else{
                curr = stk.top(); stk.pop();
                if(curr->val <= preValue){
                    return false;
                }
                preValue = curr->val;
                curr = curr->right;
            }
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        if(! root->left && ! root->right)
            return true;
        return midOrder(root);
    }
};