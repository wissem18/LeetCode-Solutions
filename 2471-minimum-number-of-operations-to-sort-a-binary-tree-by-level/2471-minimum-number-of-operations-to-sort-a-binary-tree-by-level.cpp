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
    int minimumOperations(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> a;
            while (sz--) {

                TreeNode *cur = q.front();
                q.pop();
                a.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            vector<int> b = a;
            sort(b.begin(), b.end());
            unordered_map<int, int> ind;
            for (int i = 0; i < a.size(); i++) {
                ind[a[i]] = i;
            }
            int cnt = 0;
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] != b[i]) {
                    ans++;
                    int pos=ind[b[i]];
                    ind[a[i]]=pos;
                    swap(a[i], a[pos]);
                }
            }
        }
        return ans;
    }
};