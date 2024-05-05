/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
      ListNode* cur=node;
      while(cur->next!=NULL){
          ListNode* pre=cur->next;
          cur->val=pre->val;
          if(cur->next->next==NULL) {
              cur->next=NULL;
              break;
          }
          cur=cur->next;
      }
        
    }
};