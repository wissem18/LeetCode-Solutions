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
ListNode *mergeNodes(ListNode *head) {
        ListNode *cur = head;
        int sum = 0;
        vector<int> a;
        while (cur != NULL) {
            if (cur->val == 0) {
                if (sum != 0)
                    a.push_back(sum);
                sum=0;
            } else {
                sum += cur->val;
            }
            cur = cur->next;
        }
        ListNode* ans=new ListNode(a[0]);
        ListNode* tmp=ans;
        for (int i = 1; i < a.size(); ++i) {
            tmp->next=new ListNode(a[i]);
            tmp=tmp->next;
        }
        return ans;
    }
};