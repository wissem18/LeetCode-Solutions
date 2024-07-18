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
unordered_map<TreeNode *, vector<TreeNode *>> adj;
unordered_set<TreeNode *> leaves;

void helper(TreeNode *root) {
    if (!root)
        return;
    if (!root->left && !root->right)
        leaves.insert(root);
    if (root->left) {
        adj[root].push_back(root->left);
        adj[root->left].push_back(root);
        helper(root->left);
    }

    if (root->right) {
        adj[root].push_back(root->right);
        adj[root->right].push_back(root);
        helper(root->right);
    }

}

int ans = 0;

void dfs(TreeNode *root, TreeNode *par, int distance) {
    if (distance == 0)
        return;
    for (auto node: adj[root]) {
        if (node == par)
            continue;
        if (leaves.count(node))
            ans++;
        dfs(node, root, distance - 1);
    }
}

int countPairs(TreeNode *root, int distance) {
    helper(root);
    for (auto leaf: leaves) {
        dfs(leaf, nullptr, distance);
    }
    ans /= 2;
    return ans;
}
};