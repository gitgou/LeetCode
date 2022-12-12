 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* rear2 = nullptr, * tmp = nullptr, *nodeA = nullptr, * nodeB = nullptr;
        tmp = list2;
        while(tmp->next)
            tmp = tmp->next;
        rear2 = tmp;
        int indexA = 0, indexB = 0;
        tmp = list1;
        while (tmp)
        {
            ++indexA; 
            if(indexA == a)
                nodeA = tmp;
            if(indexB == b + 1){
                nodeB = tmp;
                break;
            }
            ++indexB;
            tmp = tmp->next;
        }
        
        nodeA->next = list2;
        rear2->next = nodeB;
        return list1;
    }
};