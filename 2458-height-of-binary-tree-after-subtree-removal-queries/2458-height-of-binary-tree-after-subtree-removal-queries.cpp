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
    int height[100004];
    int pre[100004];

    int computeheights(TreeNode *root) {
        if (!root)
            return 0;
        return height[root->val] = 1 + max(computeheights(root->left), computeheights(root->right));
    }

    void dfs(TreeNode *root, int level, int maxheight) {
        if (!root)
            return;
        pre[root->val] = maxheight;
        dfs(root->left, level + 1, max(maxheight, level + 1 + ((root->right) ? height[root->right->val] : 0)));
        dfs(root->right, level + 1, max(maxheight, level + 1 + ((root->left) ? height[root->left->val] : 0)));
    }

    vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
        int m = queries.size();
        computeheights(root);
        dfs(root, 0, 0);
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            ans[i] = pre[queries[i]]-1;
        }
        return ans;
    }
};