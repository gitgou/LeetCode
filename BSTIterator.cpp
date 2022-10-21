#include <iostream>
#include<stack>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) 
    :_node(root)
    {
        //TreeNode* left = root;
        pushLeft(root);
        
    }
    void pushLeft(TreeNode* root)
    {
        TreeNode* left = root;
        while (left)
        {
            _stack.push(left);
            left = left->left;
        }        
    }
    int next() {
        TreeNode* curr = _stack.top();
        _stack.pop();
        if(curr->right)
            pushLeft(curr->right);
        
        return curr->val;
        
    }
    
    bool hasNext() {
        return ! _stack.empty();
    }

    TreeNode* _node;
    stack<TreeNode*> _stack;
};