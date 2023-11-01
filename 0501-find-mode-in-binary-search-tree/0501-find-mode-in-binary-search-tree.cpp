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
    vector<int>a;
    void dfs(TreeNode* node){
        if(!node)
            return;
        dfs(node->left);
        a.push_back(node->val);
        dfs(node->right);
    }
    vector<int> findMode(TreeNode* root) {
      dfs(root);
      vector<int>ans;
      map<int,int>occ;
        for (int i = 0; i < a.size(); ++i) {
            occ[a[i]]++;
        }
        int mx=0;
        for (auto x:occ) {
            mx=max(x.second,mx);
        }
        for (auto x:occ) {
             if(x.second==mx)
                 ans.push_back(x.first);
        }
        return ans;
    }
};