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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
        return NULL;
        ListNode *a = head->next;
        ListNode *b;
        if(head->next !=NULL)
         b= head->next->next;
        else
          b=NULL;  
        while (a != b) {
            if(a!=NULL)
            a =a->next;
            else
            return NULL;
            if(b!=NULL&&b->next!=NULL)
            b = b->next->next;
            else 
            return NULL;
        }
        a = head;
        while (a != b) {
            if(a!=NULL)
            a = a->next;
            else 
            return NULL;
            if(b!=NULL)
            b = b->next;
            else
            return NULL;
        }
        return a;
    }
};