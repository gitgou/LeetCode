 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* curr = head, *insert = nullptr;
        int tmp = 0;
        while(curr->next){
            ListNode* pre = curr;
            curr = curr->next;
            if(pre->val < curr->val){
                continue;;
            }
            
            insert = head;
            while(insert != curr)
            {
                if(insert->val > curr->val){
                    tmp = curr->val;
                    curr->val = insert->val;
                    insert->val = tmp;
                }
                insert = insert->next;
            }
        }

        return head;
    }
};