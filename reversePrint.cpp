#include<iostream>
#include<vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

    vector<int> reversePrint(ListNode* head) {
        vector<int> vec;
        vec.reserve(10000);
        ListNode* node = head;
        while(node)
        {
            vec.push_back(node->val);
            node = node->next;
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }

int main()
{
    return 0;
}