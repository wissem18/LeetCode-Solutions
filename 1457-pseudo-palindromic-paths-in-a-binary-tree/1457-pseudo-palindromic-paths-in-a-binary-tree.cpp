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
int helper(TreeNode *root, int x) {
    if (!root->left && !root->right) {
        return (x == 0 || (x & (x - 1)) == 0);
    }
    int ans = 0;
    if (root->left) {
        int v = root->left->val - 1;
        ans += helper(root->left, x ^ (1 << v));
    }
    if (root->right) {
        int v = root->right->val - 1;
        ans += helper(root->right, x ^ (1 << v));
    }
    return ans;
}

int pseudoPalindromicPaths(TreeNode *root) {
    int v = root->val - 1;
    return helper(root, 1 << v);
}
};