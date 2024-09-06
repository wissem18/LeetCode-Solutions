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
 ListNode *modifiedList(vector<int> &nums, ListNode *head) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            s.insert(nums[i]);
        }
       
        while (head != NULL && s.count(head->val)) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        if (head == NULL) {
            return NULL;
        }

        ListNode* current = head;
        while (current->next != NULL) {
            if (s.count(current->next->val)) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};