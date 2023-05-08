#include<vector>
#include<iostream>
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
    void dfs(TreeNode* root, int sum, vector<int> vecSum, vector<vector<int>>& res){
        if(!root->left && !root->right){
            if(sum == _target){
                res.push_back(vecSum);
            }
            return;
        }
        vecSum.push_back(root->val);
        sum += root->val;
        if(root->left)
            dfs(root->left, sum, vecSum, res);
        if(root->right)
            dfs(root->right, sum, vecSum, res);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int> > res;
        if(!root){
            return res;
        }
        _target = targetSum;
        dfs(root, 0, vector<int>{}, res);
    }

private: 
    int _target;
};