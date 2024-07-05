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
vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        int mn = INT_MAX, first = 0, last = 0;
        ListNode *cur = head;
        int i = 0;
        int prev = -1;
        int prevval = -1;
        while (cur) {
            if (i&&((cur->val < prevval && cur->next && cur->next->val > cur->val) ||
                (cur->val > prevval && cur->next && cur->next->val < cur->val))) {
                if (prev != -1) {
                    mn = min(mn, i - prev);
                    last=i;
                }
                else 
                    first=i;
                prev = i;
            }

            prevval = cur->val;
            cur = cur->next;
            i++;
        }
        if (mn == INT_MAX)
            return {-1, -1};
        return {mn, last - first};
    }
};