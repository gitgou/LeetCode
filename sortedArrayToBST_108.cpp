#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    TreeNode* toBST(vector<int>& nums, int left, int right){
      if(left > right)
        return nullptr;
      int mid = left + (right - left) / 2;
      TreeNode* root = new TreeNode(nums[mid]);
      root->left = toBST(nums, left, mid - 1);
      root->right = toBST(nums, mid+1, right);
      return root;  
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      if(nums.size() == 0)
        return nullptr;
      return toBST(nums, 0, nums.size() - 1);
    }

int main(){
  return 0;
}