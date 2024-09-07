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
    bool isValid(ListNode *head, TreeNode *root) {
        if (!root)
            return head == NULL;
        if (head == NULL)
            return true;
        if (root->val != head->val)
            return false;
        return isValid(head->next, root->left) || isValid(head->next, root->right);
    }

    bool dfs(ListNode *head, TreeNode *root) {
        if (!root)
            return false;
        bool x = isValid(head, root);
        if (x)
            return true;
        return dfs(head, root->left) || dfs(head, root->right);

    }

    bool isSubPath(ListNode *head, TreeNode *root) {
        
        return dfs(head, root);
    }
};