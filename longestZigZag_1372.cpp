#include <iostream>
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

    int longestZigZag(TreeNode* root) {
      res = 0;
      preOrder(root);

      return res - 1;
    }

    void preOrder(TreeNode* root){
      if(!root)
        return;

      dfs(root, 0, 0);

    }
    // 0 表示根， 1 表示右节点, 2 表示左节点
    void dfs(TreeNode* root, int nodeType, int tmp){
      if(!root)
        return;

      res = max(res, tmp+1);
      if(nodeType == 0){
        if(root->left)
          dfs(root->left, 1, tmp + 1);
        if(root->right)
          dfs(root->right, 2, tmp+1);
      }else if(nodeType == 1){
        if(root->right)
          dfs(root->right, 2, tmp+1);
        if(root->left)
          dfs(root->left, 1, 1);
      }else if(nodeType == 2){
        if(root->left)
          dfs(root->left, 1, tmp+1);
        if(root->right)
          dfs(root->right, 2, 1);
      }
    }
private:
  int res;

};