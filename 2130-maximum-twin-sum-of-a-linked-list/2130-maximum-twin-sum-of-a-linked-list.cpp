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
    int pairSum(ListNode* head) {
        int ans=0;
        ListNode* it=head;
        vector<int>a;
        while(it!=NULL){
            a.push_back(it->val);
            it=it->next;
        }
        for(int i=0;i<a.size()/2;i++){
            ans=max(ans,a[i]+a[a.size()-i-1]);
        }
        return ans;
    }
};