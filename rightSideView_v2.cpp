#include<vector>
#include<queue>
#include<iostream>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

     vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(! root)
            return res;
        TreeNode* rear = root, *node = root, *next = root;
        queue<TreeNode*> q;
        q.push(root);
        while(! q.empty()){
            node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                next = node->left;
            }

            if(node->right){
                q.push(node->right);
                next = node->right;
            }

            if(node == rear){
                res.push_back(rear->val);
                rear = next;
            }
        }

        return res;
    }