#include<iostream>
#include<unordered_set>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
    
    ListNode *detectCycle(ListNode *head) {
        if(!head || ! head->next){
            return nullptr;
        }
        ListNode* fast = head->next, * slow = head, * equal = nullptr;
        unordered_set<ListNode*> hash;
        while(fast && fast->next){
            if(fast == slow){
                equal = fast;
                break;
            }else{
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        //无环
        if(equal == nullptr){
            return nullptr;
        }  

        while(hash.insert(equal).second == true){
            equal = equal->next;
        }

        while(hash.find(head) == hash.end()){
            head = head->next;
        }      

        return head;
    }

int main(){
    return 0;
}