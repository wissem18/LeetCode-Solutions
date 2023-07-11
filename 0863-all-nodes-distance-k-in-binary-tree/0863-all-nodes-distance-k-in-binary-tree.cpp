/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> adj;

void dfs(TreeNode *root) {
    if (root == NULL)
        return;
    if (root->left) {
        adj[root->left->val].push_back(root->val);
        adj[root->val].push_back(root->left->val);
    }
    if (root->right){
        adj[root->right->val].push_back(root->val);
        adj[root->val].push_back(root->right->val);
    }
    dfs(root->left);
    dfs(root->right);    
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    adj.resize(505);
    dfs(root);
    vector<int> ans;
    queue<int> q;
    q.push(target->val);
    vector<bool> vis(501, false);
    int cnt = 0;
    vis[target->val] = true;
    while (!q.empty()) {
        if (cnt > k)
            break;
        else if (cnt == k) {
            while (!q.empty()) {
                ans.push_back(q.front());
                q.pop();
            }
        } else {
            int s = q.size();
            while (s--) {
                int cur = q.front();
                q.pop();
                for (auto next: adj[cur]) {
                    if (!vis[next]) {
                        vis[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        cnt++;
    }
    return ans;
}
};