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

    int sumNumbers(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int tmp = 0, result = 0;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                node->left->val = node->val * 10 + node->left->val;
                q.push(node->left);
            }
            if(node->right){
                node->right->val = node->val * 10 + node->right->val;
                q.push(node->right); 
            }
            
            if(!node->left && ! node->right){
                result += node->val;
            }           
        }

        return result;
    }

int main()
{
    return 0;
}