#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = head, *now = head;
        while(now != nullptr){
            while(now->val == pre->val){
                now = now->next;
            }

            while(pre->next != now){
                ListNode* tmp = pre->next;
                delete pre;
                pre = tmp;
            }
            pre = pre->next;
        }
        return head;
    }
};