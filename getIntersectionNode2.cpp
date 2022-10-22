#include<iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getListLength(ListNode* head)
    {
        int length = 0;
        while (head)
        {
            ++length;
            head = head->next;
        }
        return length;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = getListLength(headA);
        int lengthB = getListLength(headB);
        while (lengthA > lengthB)
        {
            headA = headA->next;
            --lengthA;
        }
        while(lengthA < lengthB){
            headB = headB->next;
            --lengthB;
        }        

        while (headA && headB)
        {
            if(headA == headB)
            {
                return headA;
            }else{
                headA = headA->next;
                headB = headB->next;
            }
        }

    }
};