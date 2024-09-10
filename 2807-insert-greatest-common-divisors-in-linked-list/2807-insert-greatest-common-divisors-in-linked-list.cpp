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
    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        ListNode *tmp = head;
        while (tmp->next) {
            ListNode *nxt = tmp->next;
            ListNode *cur = new ListNode(__gcd(tmp->val, nxt->val), nxt);
            tmp->next = cur;
            tmp=nxt;
        }
        return head;
    }
};