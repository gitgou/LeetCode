#include<iostream>

using namespace std;
 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* NewHead = new ListNode();
        NewHead->next = head;
        ListNode* fast = NewHead, * slow = NewHead;
        while(fast && n >= 0)
        {
            fast = fast->next;
            --n;
        }

        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* tmp = slow->next;
        //如果是倒数第一个时需要判断
        slow->next = tmp ? tmp->next : nullptr;
        delete tmp;
        tmp = NewHead->next;
        delete NewHead;
        return tmp;
    }

int main()
{
    return 0;
}