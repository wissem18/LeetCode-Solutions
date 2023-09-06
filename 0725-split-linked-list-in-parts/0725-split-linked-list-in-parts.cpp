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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int sz=0;
        ListNode* cur=head;
        while(cur!=NULL){
            sz++;
            cur=cur->next;
        }
        vector<ListNode*>ans;
        int r=sz%k;
        int t=sz/k;
        cur=head;
        while(cur)
        {
            ans.push_back(cur);
            int curl=1;
            while(curl<t)
            {
                cur=cur->next;
                curl++;
            }
            if(r>0 && t>0)
            {
                cur=cur->next;
                r--;
            }
            ListNode* tmp=cur->next;
            cur->next=NULL;
            cur=tmp;
        }
        while(sz<k)
        {
            ans.push_back(NULL);
            sz++;
        }
        return ans;
    }
};