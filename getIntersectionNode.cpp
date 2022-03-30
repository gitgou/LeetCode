#include<iostream>

using namespace std;

 struct ListNode 
 {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

    int getLength(ListNode* head)
    {
        int length = 0;
        while (head)
        {
            ++length;
            head = head->next;
        }

        return length; 
    }
     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        ListNode* tmpA = headA, * tmpB = headB;
        while (lengthA > lengthB)
        {
            --lengthA;
            tmpA = tmpA->next;
        }
        
        while(lengthA < lengthB)
        {
            --lengthB;
            tmpB = tmpB->next;
        }

        while (tmpA && tmpB && tmpA != tmpB)
        {
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }

        return tmpA; 
    }