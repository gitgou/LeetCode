#include<iostream>
#include<vector>
#include<queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> Q;
        if(!root)
            return res;
        TreeNode* rear = root, * last = root;
        Q.push(root);
        res.push_back(vector<int>());
        while(!Q.empty()){
            TreeNode* node = Q.front(); Q.pop();
            res[res.size() - 1].push_back(node->val);
            if(node->left){
                Q.push(node->left);
                last = node->left;
            }
            if(node->right){
                Q.push(node->right);
                last = node->right;
            }
            if(node == rear){
                if(!Q.empty())
                    res.push_back(vector<int>());
                rear = last;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};