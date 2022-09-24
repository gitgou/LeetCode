/***** 138. 复制带随机指针的链表 ******/
#include<iostream>
#include<unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
    //哈希表 + 回溯 绝了 通过两条链子往下创建，直到返回nullptr
    Node* copyRandomList(Node* head)
    {
        static unordered_map<Node*, Node*> mapNode;
        //使用 unordermap，查找o(1)
        if(!head)
        {
            return nullptr;
        }

        //即还没有创建
        if(mapNode.count(head) == 0)
        {
            Node* headnew = new Node(head->val);
            mapNode[head] = headnew;
            headnew->next = copyRandomList(head->next);
            headnew->random = copyRandomList(head->random);
        }

        return mapNode[head];
    }

int main()
{
    return 0;
}