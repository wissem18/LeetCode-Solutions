/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
    ListNode* it=head;
    ListNode* first;
    ListNode* second;
    for(int i=1;i<k;i++){
        it=it->next;
    }
    first=it;
    it=head;
        int l=0;
    while(it!=NULL){
        it=it->next;
        l++;
    }
        int m=l-k+1;
        it=head;
         for(int i=1;i<m;i++){
        it=it->next;
         }
    second=it;
        swap(first->val,second->val);
        return head;
    }
   };