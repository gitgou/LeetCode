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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr){
            return vector<int>();
        }
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelSize = q.size();
            int max = INT_MIN;
            while(levelSize > 0){
                TreeNode * node = q.front(); q.pop();
                if(node->val > max){
                    max = node->val;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                --levelSize;
            }
            res.push_back(max);
        }
        
        return res;
    }
};