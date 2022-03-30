#include<iostream>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* mergeList(ListNode* l , ListNode* r)
{
    ListNode tmp = ListNode();
    ListNode* head = & tmp;
    ListNode* node = head;
    while(l && r)
    {
        if(l->val > r->val)
        {
            //ListNode* next = new ListNode(r->val);
            node->next = r; 
            r = r->next;
        }
        else
        {
            node->next = l;
            l = l->next;
        }
        node = node->next;
        //node->next = nullptr;
    }

    if(l)
    {
        node->next = l;
    }

    if(r)
    {
        node->next = r;
    }

    node= head->next;
    //delete head;

    return node;
}

ListNode* sortList(ListNode* head) 
{
    //链表只有一个结点或者为null，则返回
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    //slow走一步，fast走两步，达到二路归并效果
    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //得到两个链表的头结点
    ListNode* leftNode = head;
    ListNode* rightNode = slow->next; 

    slow->next = nullptr;

    leftNode = sortList(leftNode);
    rightNode = sortList(rightNode);

    return  mergeList(leftNode, rightNode); 
}

int main()
{
    return 0;
}