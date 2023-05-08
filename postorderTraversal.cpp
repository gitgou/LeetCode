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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        while (root || !stk.empty())
        {
            while(root){
                stk.push(root);
                root = root->left;
            }
            root = stk.top(); stk.pop();
            //所有元素必须先入栈，出栈时如果右节点空或者 上一个出栈节点为自己右子节点，则遍历该节点
            if(root->right == nullptr || root->right == prev){
                res.push_back(root->val);
                prev = root;
                root = nullptr;
            }else{
                stk.emplace(root); //再继续入栈，遍历完右子树再出栈
                root = root->right; //继续遍历右子树
            }
        }
        return res; 
    }
};