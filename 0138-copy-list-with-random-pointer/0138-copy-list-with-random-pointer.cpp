/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*>copy;
        Node* cur=head;
        while(cur!=NULL){
            copy[cur]=new Node(cur->val);
            cur=cur->next;
        }
        cur=head;
        while(cur!=NULL){
            copy[cur]->next=copy[cur->next];
            copy[cur]->random=copy[cur->random];
            cur=cur->next;
        }
        return copy[head];
    }
};