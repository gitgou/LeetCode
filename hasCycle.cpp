#include <iostream>
using namespace std;
    
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;

        ListNode * fast = head->next, *slow = head;
        while(fast && fast->next)
        {
            if(fast == slow)
                return true;
            
            fast = fast->next->next;
            slow = slow->next;
        }

        return true; 
    }

int main()
{
    return 0;
}