#include<iostream>
#include<unordered_map>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    void dfs(TreeNode* node)
    {
        if(! node)
            return;
        dfs(node->left);
        dfs(node->right);

        _f[node] = node->val + _g[node->left] + _g[node->right];
        _g[node] = max(_f[node->left], _g[node->left]) + max(_f[node->right], _g[node->right]); 
    }
    int rob(TreeNode* root) {
        dfs(root);
        return max(_f[root], _g[root]);
    }

private:
    //分别表示选择该结点和不选择该结点得到的临时最优解
    unordered_map<TreeNode*, int> _f, _g;
};
int main()
{
    return 0;
}