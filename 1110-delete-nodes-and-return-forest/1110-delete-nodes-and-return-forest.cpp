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
vector<TreeNode *> ans;

TreeNode *helper(TreeNode *root, unordered_set<int> s) {
    if (!root)
        return nullptr;
    root->left = helper(root->left, s);
    root->right = helper(root->right, s);
    if (s.count(root->val)) {
        if (root->left)
            ans.push_back(root->left);
        if (root->right)
            ans.push_back(root->right);
        delete root;
        return nullptr;
    }
    return root;
}

vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    unordered_set<int> s(to_delete.begin(), to_delete.end());
    root=helper(root, s);
    if (root) {
        ans.push_back(root);
    }
    return ans;
}
};