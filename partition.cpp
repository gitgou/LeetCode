 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode * fast = head, * low = new ListNode(0), *high = new ListNode(0);
        ListNode * lowIndex = low, *highIndex = high;
        while (fast != nullptr)
        {
            if(fast->val >= x){
                highIndex->next = fast;
                highIndex = highIndex->next;       
            }else{
                lowIndex->next = fast;
                lowIndex = lowIndex->next;
            }
            fast = fast->next;
        }
        highIndex->next = nullptr;
        lowIndex->next = high->next;
        ListNode * res = low->next;
        delete low; delete high;
        return res;
    }
};