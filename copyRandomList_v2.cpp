#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution{
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        //没有遍历到的节点
        if(_hashNode.count(head) == 0){
            Node* nowNode = new Node(head->val);
            _hashNode[head] = nowNode;
            nowNode->next = copyRandomList(head->next);            
            nowNode->random = copyRandomList(head->random);            
        }

        return _hashNode[head];
    }

private:     
    unordered_map<Node*, Node*> _hashNode;
};