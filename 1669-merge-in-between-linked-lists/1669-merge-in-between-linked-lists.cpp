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
   ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        int i = 0;
        ListNode * tmp = list1;
        ListNode* left=NULL;
        while(tmp){
            if(i==a-1){
                left=tmp;
            }
            if(i==b)
                break;
            tmp=tmp->next;
            i++;
        }
        left->next=list2;
        ListNode* tmp1=list2;
        while(tmp1->next)
            tmp1=tmp1->next;
        tmp1->next=tmp->next;
        //tmp->next=NULL;
        return list1;
    }
};