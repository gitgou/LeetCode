struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode();
        ListNode * tmp = head;
        int carry = 0;
        while (l1 && l2)
        {
            tmp->next = new ListNode((l1->val + l2->val +carry) % 10);
            carry = (l1->val + l2->val +carry) / 10;
            tmp = tmp->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1)
        {
            tmp->next = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry) / 10;
            tmp = tmp->next;
            l1 = l1->next;
        }
        
        while (l2)
        {
            tmp->next = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry) / 10;
            tmp = tmp->next;
            l2 = l2->next;
        }
        
        if(carry != 0){
           tmp->next = new ListNode(carry); 
        }

        tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
};