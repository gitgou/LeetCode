#include<vector>
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
    void rightSideView(TreeNode* node, vector<int>& vec, int floor)
    {
        if(! node)
            return;
        ++floor;
        if(floor > vec.size()){
            vec.push_back(node->val);
        }
        
        if(node->right){
            rightSideView(node->right, vec, floor);
        }
        
        if(node->left){
            rightSideView(node->left, vec, floor);
        }    
         
    }

     vector<int> rightSideView(TreeNode* root) {
         vector<int> vec;
         TreeNode* node = root;
         int floor = 0;
         rightSideView(node, vec, floor);


         return vec;
    }

int main()
{
    return 0;
}