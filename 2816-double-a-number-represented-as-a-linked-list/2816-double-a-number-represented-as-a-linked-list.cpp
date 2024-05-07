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
    ListNode* doubleIt(ListNode* head) {
        if(head->val>4){
            head=new ListNode(0,head);
        } 
        
        ListNode* itr=head;
        while(itr!=NULL){
            itr->val=(itr->val*2)%10;
            
            if(itr->next!=NULL &&itr->next->val>4)//there is a carry from the next digit 
                itr->val++;
            itr=itr->next;
        }
        return head;
    }
};