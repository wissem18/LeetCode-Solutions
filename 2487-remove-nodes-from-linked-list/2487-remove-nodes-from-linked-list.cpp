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
    ListNode *removeNodes(ListNode *head) {
        vector<int> a;
        while (head != NULL) {
            a.push_back(head->val);
            head = head->next;
        }
        vector<int> mx(a.size());
        int cur = 0;
        for (int i = mx.size() - 1; i >= 0; --i) {
            cur = max(cur, a[i]);
            mx[i] = cur;
        }
        ListNode *ans = new ListNode();
        ListNode * ptr;
        int cnt=0;
        for (int i = 0; i < a.size(); ++i) {
          if(a[i]>=mx[i]){
              if(!cnt){
                  ans->val=a[i];
                  ptr=ans;
                  cnt++;
              }
              else{
                  ptr->next=new ListNode(a[i]);
                  ptr=ptr->next;
              }
          }
        }
        return ans;
    }
};