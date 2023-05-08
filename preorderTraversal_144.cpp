#include<vector>
#include<stack>

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty())
        {
            root = stk.top(); stk.pop();
            res.push_back(root->val);
            if(root->right)
                stk.push(root->right);
            if(root->left){
                stk.push(root->left);
            }
        }
        return res;   
    }
};