#include<iostream>
#include<vector>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

     void deleteNode(ListNode* node) {
        bool flag = true;
        ListNode* next = node->next, *before = node;
        while(node){
            if(next){
                node->val = next->val;
                node = node->next;
                next = next->next;
                if(!flag)
                    before = before->next;
                flag = false;
            }else{
                before->next = nullptr;
                node = nullptr;
            }
        } 
        
    }