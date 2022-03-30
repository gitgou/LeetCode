#include<iostream>
#include<vector>

using namespace std;
 //Definition for singly-linked list.
 struct ListNode 
 {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre = nullptr, * now = head;
        while (now)
        {
            ListNode* next = now->next;
            now->next = pre;
            pre = head = now;
            now = next;
        }
        
        return head;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode* leftNode = head, *rightNode = head, * preLeft = nullptr, *rightNext = head;

        int tmpRight = right;
        while( --tmpRight > 0 && leftNode)
        {
            if((right - tmpRight)  < left)
            {
                preLeft = leftNode;
                leftNode = leftNode->next;  
            } 

            rightNode = rightNode->next;
                    
        }

        rightNext = rightNode->next;
        rightNode->next = nullptr;
        //cout << "rightNext: " << rightNext->val << endl;
        //cout << "preLeft: " << preLeft->val << endl;
        //cout << "leftnode: " << leftNode->val << endl;
        //cout << "rightNode: " << rightNode->val << endl;

        ListNode* node = reverseList(leftNode);
        if(preLeft)
        {
            preLeft->next = node;
        }
        else
        {
            head = node;
        }
        leftNode->next = rightNext;
        return head;
    }

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* tmp = head;
    for(int i = 1; i < 5; ++i)
    {
        ListNode* node = new ListNode(i);
        tmp->next = node;
        tmp = tmp->next;
    }
    head = reverseBetween(head, 1, 5);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }


    cout << endl;
    

    return 0;
}