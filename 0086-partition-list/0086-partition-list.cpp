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
ListNode *partition(ListNode *head, int x) {
    ListNode *small = new ListNode(0);
    ListNode *big = new ListNode(0);
    ListNode *leftNode = small;
    ListNode *rightNode = big;

    while (head!=NULL) {
        if (head->val < x) {
            leftNode->next = head;
            leftNode = leftNode->next;
        } 
        else {
            rightNode->next = head;
            rightNode = rightNode->next;
        }
        head = head->next;
    }

    leftNode->next = big->next;
    rightNode->next = NULL;
    return small->next;
}
};