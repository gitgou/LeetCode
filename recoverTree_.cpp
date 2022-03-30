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

/*
    二叉搜索树的中序遍历可以得到树有序序列。
    利用这个特性，且因树中仅有两个结点被交换。
    所以使用中序遍历时，
    1:当出现第一个乱序结点时(即上一个遍历的结点 -- pre, 比当前结点 -- root大时)，
    则此时的(上一个结点 -- pre) 一定是整个树中被交换的结点之一；
    2:继续遍历到第二个乱序结点时，
    此时的当前结点 -- root 是整个树中被交换的结点之一。
    因为，如果两个结点被交换，那么我们首先遍历到的交换结点应该是比它附近的结点都要大，
    该结点比交换位置的下一个结点要大；再次遍历到的结点应该比它附近的结点都要小；
    选择与遍历上一个结点相比的原因是我们在遍历中只能记录上一个结点。

    3:得到两个被交换的结点后结束递归，并且置换两个被交换结点的值。
    完事~~
*/
    //指针pre recover1 recover一定要时指针引用类型。
    void middle(TreeNode* root, TreeNode*& pre, TreeNode* &recover1, TreeNode* &recover2)
    {
        if(! root)
        {
            return;
        }

        middle(root->left, pre, recover1, recover2);
        //向前一个元素比，是否比前一个元素小，
        if(pre && pre->val > root->val)
        {
            recover1 = pre;
        }
        //以前面的元素向后比，找到小的数变换到后面的位置，进行交换
        if(pre && recover1 && pre->val > root->val)
        {
           // 因为在找recover1时会进入到该循环中，但可能得到recover2并非真正的被交换节点
           //所以需要else if来判断。 
            cout << "result1: " << recover1->val << " result2: " << root->val << endl;
            if(! recover2)
            {
                recover2 = root;
            } 
            else if (recover2 && recover2->val > root->val)
            {
                recover2 = root;
            }
            
        }

        pre = root;

        middle(root->right, pre, recover1, recover2);
    }


    
    void recoverTree(TreeNode* root) 
    {
        //注意野指针
        TreeNode* recover1 = nullptr;
        TreeNode* recover2 = nullptr;
        TreeNode* pre = nullptr;
        middle(root, pre, recover1, recover2);

        std::swap(recover1->val, recover2->val);

    }

int main()
{

    return 0;
}