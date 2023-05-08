struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || ! head->next)
            return nullptr;
        
        ListNode * slow = head, * fast = head->next;
        while(fast && n-- > 0){
            fast = fast->next;
        }

        if(n == 1){
            head = head->next;
            return head;
        }
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};