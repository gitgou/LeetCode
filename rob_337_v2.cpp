 #include<vector>
 #include<unordered_map>
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
    void dfs(TreeNode* node){
        if(!node)
            return;
        dfs(node->left);
        dfs(node->right);

        f[node] = node->val + g[node->left] + g[node->right];
        g[node] = std::max(f[node->left], g[node->left]) + std::max(f[node->right], g[node->right]);

    }
    //后序遍历 + 动态规划   
    int rob(TreeNode* root) {
        dfs(root);

        return std::max(f[root], g[root]);
    }

private: 
    //选择该节点或不选
    std::unordered_map<TreeNode*, int> f, g;
};