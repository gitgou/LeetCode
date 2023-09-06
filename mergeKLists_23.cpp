#include<vector>
#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

    ListNode* mergeKLists(vector<ListNode*>& lists) {
      int n = lists.size();
      if(n == 0)
        return nullptr;
      
      ListNode* head = new ListNode(0);
      ListNode* currNode = head;
      //vector<int> indexs(n, 0);
      bool exist = false;
      while (!exist)
      {
        int minNum = INT_MAX, minIndex = -1;
        exist = true;
        for(int i = 0; i < n; ++i){
          ListNode* tmp = lists[i];
          if(!tmp)
            continue;

          exist = false;
          if(tmp->val < minNum){
            minIndex = i;
            minNum = tmp->val;
          }
        }

        if(minIndex != -1){
          currNode->next = lists[minIndex];
          currNode = currNode->next;
          lists[minIndex] = currNode->next;
          currNode->next = nullptr;
        }
      }

      ListNode* tmp = head->next;
      delete head;
      return tmp; 
    }

int main(){

  return 0;
}