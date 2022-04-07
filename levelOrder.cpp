#include<vector>
#include<iostream>
#include<queue>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

    vector<vector<int> > levelOrder(TreeNode* root) {

        vector<vector<int> > result;
        if(! root)
            return result; 

        queue<TreeNode*> q;
        q.push(root);
        result.push_back(vector<int>());
        int level = 0;
        TreeNode* last = root, * rear = root;
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            result[level].push_back(node->val);
            if(node->left){
                q.push(node->left);
                rear = node->left;
            }
            if(node->right){
                q.push(node->right);
                rear = node->right;
            }
            
            if(node == last){
                //翻转元素
                if(level % 2 == 1)
                    reverse(result[level].begin(), result[level].end());
                
                if(rear != last){
                    ++level;
                    result.push_back(vector<int>());
                    last = rear;
                }
            }
            
        }

        return result; 
    }

int main()
{
    return 0;
}