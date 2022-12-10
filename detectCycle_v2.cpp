 #include<iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || ! head->next || !head->next->next)
            return nullptr;
        ListNode* slow = head, *fast = head;
        do{
            slow = slow->next;
            fast = fast->next->next;
        }while(fast && fast->next && fast != slow);

        if(fast != slow)
            return nullptr;
        
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};