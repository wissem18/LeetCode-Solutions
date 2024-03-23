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
    void reorderList(ListNode* head) {
            vector<int> a;
        ListNode * tmp=head;
        while (tmp) {
            a.push_back(tmp->val);
            tmp = tmp->next;
        }
        ListNode *it = head;
        for (int i = a.size()-1; i > a.size() / 2; --i) {
            ListNode *nw = new ListNode(a[i]);
            nw->next=it->next;
            it->next=nw;
            it=it->next->next;
        }
        if(a.size()%2==0)
            it->next->next=NULL;
        else
            it->next=NULL;
    }
};