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
    bool isPalindrome(ListNode* head) {
    vector<int>a;
        a.push_back(head->val);
        while(head->next){
            head=head->next;
            a.push_back(head->val);
        }
        for(int i=0;i<a.size()/2;i++){
            if(a[i]!=a[a.size()-1-i])
                return false;
        }
        return true;
    }
};