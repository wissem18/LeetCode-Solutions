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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* rec(ListNode* head,ListNode* tail){
        if(head==tail)//the list is empty
        return NULL;
        if(head->next==tail){//the list has only one element
            TreeNode* root=new TreeNode(head->val);
            return root;
        }
        ListNode* mid=head;ListNode* last=head;
        while(last!=tail&&last->next!=tail){
            mid=mid->next;
            last=last->next->next;
        }
      TreeNode* root=new TreeNode(mid->val);
      root->left=rec(head,mid);
      root->right=rec(mid->next,tail);  
      return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return rec(head,NULL);
    }
};