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
int sumOfLevels[100000];

void precompute(TreeNode *root, int level) {
    if (!root)
        return;
    sumOfLevels[level] += root->val;
    precompute(root->left, level + 1);
    precompute(root->right, level + 1);

}

void compute(TreeNode *root, int sibling, int level) {
    if (!root)
        return;
    int left = ((root->left) ? root->left->val : 0);
    int right = ((root->right) ? root->right->val : 0);
    if (level == 1)
        root->val = 0;
    else
        root->val = sumOfLevels[level] - root->val - sibling;
    compute(root->left, right, level + 1);
    compute(root->right, left, level + 1);
}

TreeNode *replaceValueInTree(TreeNode *root) {
    if (!root)
        return NULL;
    precompute(root, 0);
    root->val = 0;
    compute(root->left, 0, 1);
    compute(root->right, 0, 1);
    return root;
}
};