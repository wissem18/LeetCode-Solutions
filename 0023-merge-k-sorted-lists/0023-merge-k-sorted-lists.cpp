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
       ListNode* mergeKLists(vector<ListNode*>& lists) {
     priority_queue<int>q;
        for (int i = 0; i < lists.size();++i) {
            ListNode* x=lists[i];
            while(x!=NULL){
                q.push(x->val);
                x=x->next;
            }
        }
        ListNode* res=NULL;
       while(!q.empty()){
           ListNode* temp = new ListNode(q.top(),res);
           res=temp;
           q.pop();
       }
       return res;
    }
};