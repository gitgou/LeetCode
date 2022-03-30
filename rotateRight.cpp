#include <iostream>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void PrintList(ListNode* head)
{
     while (head)   
    {
        cout << head->val << " ";
        head = head->next;
    }  
    cout << endl; 
}

//寻找倒数第k个节点
ListNode* k_node(ListNode* head, int k)
{
    if(head == nullptr)
    {
        return nullptr;
    }

    ListNode* fast = head; ListNode* slow = head;
    for(int i = 0; i < k; ++i)
    {
        fast = fast->next;
    }

    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    return slow;
}

ListNode* rotateRight(ListNode* head, int k) 
{
    if(head == nullptr)
    {
        return nullptr;
    }

    //求长度
    size_t length = 0;
    ListNode* node = head;
    while(node) 
    {
        ++length;
        node = node->next;
    }

    if(k % length == 0)
    {
        return head;
    }

    k = k % length;

    ListNode* tmp = k_node(head, k);
    //PrintList(tmp);
    ListNode* result = node = tmp->next;
    tmp->next = nullptr;

    while(node->next)
    {
        node = node->next;
    }

    node->next = head;

    return result;
    
}

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* node = head;
    for(int i = 1; i < 5; ++i)
    {
        node->next = new ListNode(i);
        node = node->next;
    }
    //PrintList(head);
    ListNode* result = head = rotateRight(head, 2);

    //PrintList(result);

    while(!head)
    {
        node = head;
        head = head->next;
        delete node;
    }

    return 0;
}