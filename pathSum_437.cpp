#include <iostream>
#include<vector>
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

class Solution {
public:

    int pathSum(TreeNode* root, int targetSum) {
      res = 0;
      preOrder(root, targetSum);

      return res;
    }

    void preOrder(TreeNode* root, long long targetSum){
      if(!root)
        return

      dfs(root, targetSum);

      if(root->left)
        preOrder(root->left, targetSum);
      if(root->right)
        preOrder(root->right, targetSum);

    }
    void dfs(TreeNode* root, long long targetSum){
      if(!root)
        return;

      if(root->val == targetSum){
        res++;
        return;
      }
      if(root->left)
        dfs(root->left, targetSum - root->val);
      
      if(root->right)
        dfs(root->right, targetSum - root->val);
    }
private:
  int res;
};

int main(){

  return 0;
}