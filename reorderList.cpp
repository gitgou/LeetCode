 struct ListNode {
 int val;
 struct ListNode *next;
 };
 

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* reorderList(ListNode* head) {
        // write code here
        ListNode * curr = head, *pre = head, *tmp = head;
        ListNode* res = new ListNode(), * insert = res;
        int length = 0;
        while(tmp){
            length++;
            tmp = tmp->next;
        }

        int size = 0;
        while(size < length / 4){
            tmp = curr->next->next->next->next;
            res->next = curr->next->next;
            res = res->next;
            res->next = curr;
            res = res->next->next;
            res->next = nullptr;
            curr = tmp;
            ++size;
        }
        if(length % 4 == 1 ){
            res->next = curr;
            res->next->next = nullptr;
        }else if(length % 4 == 2){
            res->next = curr;
            res->next->next = nullptr;
        }else if(length % 4 == 3){
            res->next == curr->next->next;
            res = res->next;
            res->next = curr;
            res->next->next = nullptr;
        }

        tmp = insert->next;
        delete insert;
        return tmp;
    }
};